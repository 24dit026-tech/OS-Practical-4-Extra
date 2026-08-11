#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid = fork();

    if(pid == 0)
    {
        sleep(5);

        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("New Parent PID: %d\n", getppid());
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());

        sleep(2);

        printf("Parent Exiting\n");
        exit(0);
    }

    return 0;
}
