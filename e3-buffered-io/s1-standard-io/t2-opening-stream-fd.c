#include <stdio.h>
#include "../../apue.h"


// FILE * fdopen(int fd, const char *mode)
void main() {
    int fd;
    FILE *fp;

    fd = open("open.txt", O_RDONLY);
    fd = -1; // intentionally placed to give fd a bad value
    fp = fdopen(fd, "r");

    if (fp == NULL) {
        char *er = strerror(errno);
        printf("%s\n", er);
    }
}