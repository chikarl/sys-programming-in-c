#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
    this is to demonstrate the fork() system call. A successful call to fork() creates a new process.
    The new process is identical in almost in all aspects to the invoking process. Both processes 
    continue to run, returning from fork() as if nothing special had happened.

    The new process is called the child of the original process, which in turn is called the parent.
    In the child, a successful invocation of fork() returns 0.
    In the parent, fork() returns the pid of the child. The child and parent process are identical 
    in nearly every way, except for a few necessary differences:
        - the pid of the child is, of course, newly allocated, and different from that of the parent.
        - the child's parent pid is set to the pid of its process.
        - resource statistics are reset to zero in the child.
        - any pending signals are cleared, and not inherited by the child.
        - any acquired file locks are not inherited by the child.

    On error, a child process is not created, fork() returns -1, and "errno" is set appropriately.
    There are two possible "errno" values: EAGAIN, ENOMEM.
    */

    // example

    pid_t pid;

    pid = fork();

    if(pid < 0) {
        printf("Error forking\n");
    } else if (pid == 0) {
        printf("Currently in child process\n");
    } else {
        printf("Currently in parent process\n");
    }
}