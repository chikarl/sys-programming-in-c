#include <stdio.h>
#include "../../apue.h"
int main() {
    FILE *fp;

    // FILE * open (const char *path, const char *mode)
    /*
        The function opens the file path according to the given modes, and associates a new stream with it.

        Modes: this argument describes how to open the given file. Refer to page 76 of 396.

        On success, fopen() returns a valid FILE pointer, else it returns a NULL and sets errno appropriately.

    */
    fp = fopen("open.txt", "r");
    if (fp == NULL) {
        char *er = strerror(errno);
        printf("%s\n", er);
    }

}