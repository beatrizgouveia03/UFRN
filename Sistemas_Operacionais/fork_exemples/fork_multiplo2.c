#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid[5] = { -1, -1, -1, -1, -1};
    int status;
    
    pid[0] = fork();
    if (pid[0] < 0)
    {
        printf("Erro ao criar processo #0\n");
        return 1;
    }
    if(pid[0] > 0)
    {
        printf("PAI: criando o segundo processo\n");
        pid[1] = fork();
        if (pid[1] < 0)
        {
            printf("Erro ao criar processo #1\n");
            return 1;
        }
    }

    if(pid[0] == 0)
    {
        printf("FILHO#0: Criando o processo filho do filho cujo PID é %d\n", getpid());
        pid[2] = fork();
    }
    if (pid[1] == 0)
    {
        printf("FILHO#1: Criando o processo filho do filho #1\n");
        pid[3] = fork();
    }
    if ((pid[2] == 0) || (pid[3] == 0))
    {
        //for(;;);
    }
    else
    {
        status = wait(NULL);
        printf("O processo-filho #%d terminou.\n", status);
    }

    return 0;
}