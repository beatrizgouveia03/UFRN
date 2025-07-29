#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>

//Global variables
int a = 0;

void implementacao_filho1(int *a)
{
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
    char *mem;

    //Criação do segmento de memória compartilhada
    int seg_id = shmget(IPC_PRIVATE, 20*sizeof(char), IPC_CREAT | 0666);

    printf("Pai começou (PID = %d)\n", getpid());

    filho1 = fork();

    if(filho1 == 0)
    {
        implementacao_filho1(&a);
        mem = (char *)shmat(seg_id, NULL, 0);               // Anexa o processo ao segmento de memória
        sprintf(mem, "escrevendo teste");                   //Escreve na memória compartilhada
        printf("%s no processo PID = %d\n", mem, getpid()); //Lê a memória compartilhada
        shmdt(mem);                                         //Libera a memória alocada
        _exit(0);
    }

    status = wait(NULL);

    if(filho1 > 0)
    {
        filho2 = fork();

        if(!filho2)
        {
            implementacao_filho2(&a);
            mem = (char *)shmat(seg_id, NULL, 0);               // Anexa o processo ao segmento de memória
            printf("%s no processo PID = %d\n", mem, getpid()); // Lê a memória compartilhada
            shmdt(mem);                                         // Libera a memória alocada
            exit(0);
        }
    }

    status = wait(NULL);
    printf("(PID = %d) Processo sendo finalizado\n", getpid());
    printf("valor final de a = %d\n", a);
    shmctl(seg_id, IPC_RMID, NULL);                             // Desfaz o segmento de memória compartilhada
    exit(0);
    printf("Pai terminou\n");

    return 0;
}