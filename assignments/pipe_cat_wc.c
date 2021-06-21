#include "apue.h"
#include <sys/fcntl.h>

void get_lw(char *string_to_count, int arr[]) {
    int curr = FLAG_OFF;
    int char_wc = 0;  // word count
    int charl = 0;

    // Go through each character of the string param. The pointer is by default
    // set to the first item of this array.
    while (*string_to_count)
    {
        // If next character is a separator, set the current as FLAG_OFF
        if (*string_to_count == ' ' 
        || *string_to_count == '\n' 
        || *string_to_count == '\t') {
            if(*string_to_count == '\n') {
                // this nested condition is the driver for counting the number of line breaks.
                ++charl;
            } curr = FLAG_OFF;
        }
        // If next character is not a word separator and the current is at FLAG_OUT, 
        // then set the state as FLAG_ON and increment the value of word count
        else if (curr == FLAG_OFF){
            curr = FLAG_ON;
            ++char_wc;
        }
        // this will move the pointer to the next character in the array.
        // on completion, this will point to a null memloc of which 'while' can not venture.
        ++string_to_count;
    } arr[0] = charl; arr[1] = char_wc;
}


int main(int argc, char *argv[]) {
    char* file_dir = argv[1];
    int size, fd[2];
    pid_t pid;
    char line[MAXLINE];

    // try creating a pipe from the parent process
    if (pipe(fd) <0) {
        printf("Creating pipe failed!");
        exit(0);
    }
    if ((pid = fork()) < 0) {
        printf("Forking parent process into child!"); // in case the current fork() call failed
    } else if (pid > 0) {
        // currently in the parent process
        int fdf = open(file_dir, O_RDONLY); // open the file passed in as argument and store fd in fdf
        size = read(fdf, line, MAXLINE); // reads the contents of the file indexed by fdf into the buffer, line
        close(fd[0]); // close the file indexed by fdf
        write(fd[1], line, size); // write the contents of the buffer (line) to fd[1]
    } else {
        // currently in the child process
        close(fd[1]);
        int line_size = read(fd[0], line, MAXLINE); // read the contents of the fd[2]
        char character_count[MAXLINE]; 
        sprintf(character_count, "%d", line_size); // convert integer into a char array

        int l_and_w_count[2]; // array to store line and word count
        get_lw(line, l_and_w_count);
        int clines = l_and_w_count[0]; int cwords = l_and_w_count[1];

        char count_words[MAXLINE]; sprintf(count_words, "%d", cwords); 
        char count_lines[MAXLINE]; sprintf(count_lines, "%d", clines); // inverted humans like claimin
        char final_out[] = "\t"; // initial the final result char to first strcat on the rest
        strcat(final_out, count_lines);
        strcat(final_out,"\t"); strcat(final_out,count_words); 
        strcat(final_out,"\t"); strcat(final_out,character_count);
        
        write(STDOUT_FILENO, final_out, 10);
    } exit(0);
}
