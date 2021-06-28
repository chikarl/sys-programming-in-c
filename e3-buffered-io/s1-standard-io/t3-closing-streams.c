#include <stdio.h>
#include "../../apue.h"

// int fclose (FILE *stream) : to close a specific stream

// int fcloseall(void) : to close all streams

int main() {
    FILE *fp;

    fp = fopen("open.txt", "r");
    if (fp == NULL) {
        char *er = strerror(errno);
        printf("%s\n", er);
    }

    // here
    int fc = fclose(fp);
    if (fc < 0) {
        char *er = strerror(errno);
        printf("%s\n", er);
    } else {
        printf("Close file success");
    }


    // 

}