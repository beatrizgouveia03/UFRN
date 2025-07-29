#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid, pid1;

    pid = fork();

    if(pid < 0)
    {
        printf("Erro ao criar processo\n");
        return 1;
    }   
    else if (pid == 0){
        pid1 = getpid();

        printf("Filho: pid %d\n", pid);
        printf("Filho:   pid1 %d\n", pid1);
    }
    else{
        pid1 = getpid();
        printf("Pai: pid %d\n", pid);
        printf("Pai:   pid1 %d\n", pid1);
        wait(NULL); 
    }

    return 0;
}
