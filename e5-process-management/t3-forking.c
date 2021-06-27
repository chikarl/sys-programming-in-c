#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int global_var = 0;

int main() {
    int local_var = 10;
    pid_t pid; pid_t cpid;

    pid = fork();

    if(pid < 0) {
        printf("Error forking\n");
    } else if (pid == 0) {
        printf("Child process\n");
        sleep(20000);
        printf("Still sleeping");
    } else {
        printf("Parent process\n");
        //exit(0);
    }
}