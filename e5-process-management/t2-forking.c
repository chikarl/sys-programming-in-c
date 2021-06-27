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
        printf("Currently in child process\n");
        
        cpid = getpid();
        printf("ppid = %d\n", cpid);
        
        printf("local_var = %d : global_var = %d\n", local_var, global_var);
        
    } else {
        printf("Currently in parent process\n");
        
        cpid = getpid();
        printf("ppid = %d\n", cpid);
        
        printf("local_var = %d : global_var = %d\n", local_var, global_var);
        
    }

    local_var++; global_var++;
}