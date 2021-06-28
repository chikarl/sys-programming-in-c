#include <stdio.h>
#include "../../apue.h"

// int fgetc(FILE *stream)

/*
This function reads the next character from the stream and returns it as an unsigned character cast to an int.
The casting is done to have a sufficient range for notification of end-of-file or error: EOF is returned in such conditions.
The return value of fgetc() must be stored in an int. Storing it in char is a common but dangerous mistake.
*/

int main() {
    FILE *fp;
    int c;
    printf("EOF = %d\n", EOF);

    fp = fopen("open.txt", "r");
    if (!fp) {
        char *er = strerror(errno);
        printf("%s\n", er);
    } else {
        // reading just the pointer fp
        printf("Reading just the pointer fp\n");
        c = fgetc(fp);
        if (c == EOF) {
            char *er = strerror(errno);
            printf("%s\n", er);
            exit(0);
        } else {
            printf("%d = %c\n", c, (char) c);
        } printf("End\n\n");

    }
}