#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if(pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());

        sleep(20);

        wait(NULL);

        printf("Zombie removed\n");
    }

    return 0;
}
