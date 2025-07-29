#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{

    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        printf("Erro ao criar processo\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Esta é a execução do filho( PID = %d ), cujo pai tem PID =%d \n", getpid(), getppid());
    }  
    else
    {
        wait(NULL);
        printf("Processo-filho finalizado\n");
    }

    return 0;
}