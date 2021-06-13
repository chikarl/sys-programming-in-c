#include <stdio.h>
#include <sys/stat.h> // required for us to use the open() system call
#include <sys/types.h>
#include <fcntl.h> // required for us to use the open flags

int main(void) {
    int fd = 0;
    // This is the path to a text file in my computer. The system call below opens it with readonly flag
    fd = open("/home/kanye/Development/C/system-programming-in-c/e1-file-io/example-file.txt", O_RDONLY);
    if(fd == -1) {
        printf("Error reading file - try A");
    } else {
        printf("fd = %d - try A\n", fd);
    }
    
    // This time, I set the path to a file that does not exist. See the output
    fd = open("/home/kanye/Deelopment/C/example-file.txt", O_RDONLY);
    if(fd == -1) {
        printf("Error reading file - try B");
    } else {
        printf("fd = %d - try B\n", fd);
    }    // When doing this on your computer, make sure to change to valid paths.
}