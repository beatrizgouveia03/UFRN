#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int a = 0;

void implementacao_filho1(int *a){
        *a = *a + 1;
        printf("executando filho 1 = %d\n", getpid());
}

void implementacao_filho2(int *a)
{
    *a = *a + 2;
    printf("executando filho 2 = %d\n", getpid());
}

int main()
{
    int filho1, filho2, pid, status;
    printf("Pai começou (PID = %d)\n", getpid());

    filho1 = fork();
    if(!filho1)
    {
        implementacao_filho1(&a);
        printf("PID = %d; Valor de a = %d\n", getpid(), a);
        _exit(0);
    }
    
    wait(NULL);

    if(filho1 > 0){
        filho2 = fork();
        if (!filho2)
        {
            implementacao_filho2(&a);
            printf("PID = %d; Valor de a = %d\n", getpid(), a);
            _exit(0);
        }
    }

    pid = wait(NULL);
    printf("(PID = %d), o pid do processo finalizado é: %d\n", getpid(), pid);
    printf("valor final de a = %d\n", a);

    _exit(0);
    printf("Pai terminou\n");

    return 0;
}