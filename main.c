#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    printf("press enter");
    fgetc(stdin);

    pid = fork();

    if(-1 == pid)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if(0 == pid)
    {
        printf("child started, pid: %d\n", getpid());
        printf("child, waiting for enter\n");
        fgetc(stdin);
        _exit(EXIT_SUCCESS);
    }
    else
    {
        printf("main process, waiting for child\n");
        int status;
        (void)waitpid(pid, &status, 0);
    }

    return EXIT_SUCCESS;
}

