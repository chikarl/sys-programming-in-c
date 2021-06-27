#include "../apue.h"

// I guess this is my own implementation of the "cp" program in linux
int main(int argc, char *argv[]) {
    char *source = argv[1];
    char *dest = argv[2];

    int src_fd, dest_fd;

    src_fd = open(source, O_RDONLY);
    if (src_fd < 0) {
        char *er = strerror(errno);
        printf("%s\n", er);
    } else {
        dest_fd = open(dest, O_RDWR | O_CREAT | O_TRUNC);

    }
}