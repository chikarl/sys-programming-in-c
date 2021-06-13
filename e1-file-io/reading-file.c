#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(void) {
    int fd, no_of_bytes_read;
    unsigned long word;
    ssize_t nr;

    // first, we open the file using the open syscall
    fd = open("kanye-file-to-read.txt", O_RDWR);
    printf("fd = %d\n", fd);
    
    // then we read the file. this syscall returns the number of bytes read from the file given by fd
    no_of_bytes_read = read(fd, &word, sizeof(unsigned long));
    printf("number of bytes read = %d\n", no_of_bytes_read);

    close(fd);
}