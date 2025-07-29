#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    pid_t pid1, pid2;

    //Criando o primeiro filho
    pid1 = fork();
    if(pid1 < 0)
    {
        printf("Erro ao criar processo filho#1\n");
        return 1;
    }
    else if(pid1 > 0)
    {
        //Processo pai

        // Criando o segundo filho
        pid2 = fork();
        if (pid2 < 0)
        {
            printf("Erro ao criar processo filho#2\n");
            return 1;
        }
    }
    
    if(pid1 > 0 && pid2 > 0){
        
        for (int i = 1; i <= 50; i++)
        {
            printf("PID = %d\n i = %d\n", getpid(), i);
            sleep(1);
        }
        
    }

    //Funções dos filhos
    if(pid1 == 0)
    {
        printf("Filho 1 criado\n");

        for(int i=100; i <= 199; i++)
        {
            printf("PID = %d\n PPID = %d\n i = %d\n", getpid(), getppid(), i);
            sleep(0.5);
        }

        printf("Filho 1 vai morrer\n");

        return 0;
    }
    if (pid2 == 0)
    {
        printf("Filho 2 criado\n");

        for (int i = 200; i <= 299; i++)
        {
            printf("PID = %d\n PPID = %d\n i = %d\n", getpid(), getppid(), i);
            sleep(0.5);
        }

        printf("Filho 2 vai morrer\n");

        return 0;
    }

    

    return 0;
}