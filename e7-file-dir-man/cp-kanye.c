#include "../apue.h"

// I guess this is my own implementation of the "cp" program in linux
int main(int argc, char *argv[]) {
    char *source = argv[1];
    char *dest = argv[2];
    char line[MAXLINE];

    int src_fd, dest_fd, nb;

    src_fd = open(source, O_RDONLY);
    if (src_fd < 0) {
        char *er = strerror(errno);
        printf("%s\n", er);
    } else {
        dest_fd = creat(dest, 0644);
        if (dest_fd < 0) {
            char *er = strerror(errno);
            printf("%s\n", er);
        } else {
            nb = read(src_fd, line, MAXLINE);
            write(dest_fd, line, nb);
            printf("Success");
        }
        close(dest_fd);
    }
    close(src_fd);
}