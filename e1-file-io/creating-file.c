#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
    int fd;
    fd = creat("creating-file.txt", 0644);
    if (fd == -1) {
        printf("Error creating file\n");
    } else {
        printf("fd = %d - TRY A\n");
    }
    // or using our kanye created function below
    fd = kanye_creat("kanye-creating-file.txt", 0644);
    if(fd == -1) {
        printf("Error creating file\n");
    } else {
        printf("fd = %d - TRY B\n", fd);
    }
}
// we can also implement the creat() system call as a function on our own
// check this out
int kanye_creat(const char *name, int mode) {
    int fd;
    fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, mode);
    return fd;
}