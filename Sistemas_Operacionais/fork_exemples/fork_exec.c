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
        fprintf(stderr, "Criação falhou");
        _exit(-1);
    }
    else if (pid == 0)
    {
        printf("Esta é a execução do filho( PID = %d ), cujo pai tem PID =%d \n", getpid(), getppid());
        execlp("/bin/ls", "ls", "-l", NULL);
        printf("Testando o execlp\n");
        _exit(0);    
    }  
    else
    {
        wait(NULL);
        printf("Processo-filho finalizado\n");
        _exit(0);
    }

    return 0;
}