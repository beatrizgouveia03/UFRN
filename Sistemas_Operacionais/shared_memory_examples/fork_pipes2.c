#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_SIZE 4

int main(int argc, char const *argv[])
{
    pid_t pid;
    int num, resposta;
    char buffer[MAX_SIZE];
    int vetor_pipe_ida[2], vetor_pipe_volta[2]; // 0 para leitura e 1 para escrita

    pipe(vetor_pipe_ida); // Criação do pipe
    pipe(vetor_pipe_volta); // Criação do pipe

    pid = fork();     // Criação do novo processo

    if (pid == 0)
    {
        close(vetor_pipe_ida[1]);                               // Fecha o caminho de escrita
        while (read(vetor_pipe_ida[0], buffer, MAX_SIZE) > 0)  // Lê enquanto não for EOF
        
        sscanf(buffer, "%d", &num);
        close(vetor_pipe_ida[0]);                               // Fecha o caminho de leitura
        printf("FILHO: O filho leu: %d\n", num);

        /*Respondendo ao pai*/

        num += 1;
        sprintf(buffer, "%d", num);

        close(vetor_pipe_volta[0]);                             // Fecha o caminho de leitura

        write(vetor_pipe_volta[1], buffer, MAX_SIZE);           // Escreve para o pai
        close(vetor_pipe_volta[1]);                             // Fecha o caminho de escrita

        printf("FILHO: O filho escreveu: %d\n", num);
        printf("FILHO: O filho terminou\n");
        exit(0);
    }
    else
    {
        num = atoi(argv[1]);
        sprintf(buffer, "%d", num);
        close(vetor_pipe_ida[0]);                               // Fecha o caminho de leitura
        write(vetor_pipe_ida[1], buffer, MAX_SIZE);             // Escreve o conteúdo do buffer
        close(vetor_pipe_ida[1]);                               // Fecha o caminho de escrita (EOF)
        printf("PAI: O pai escreveu: %s\n", buffer);
        
        /*Lendo do filho*/
        close(vetor_pipe_volta[1]);                             // Fecha o caminho de escrita
        while (read(vetor_pipe_volta[0], buffer, MAX_SIZE) > 0) // Lê enquanto não for EOF
        close(vetor_pipe_volta[0]);                             // Fecha o caminho de leitura
        sscanf(buffer, "%d", &num);
        printf("PAI: O pai leu: %d\n", num);

        wait(NULL);
        printf("PAI: O filho terminou\n");
        printf("PAI: O pai terminou\n");
        exit(0);
    }

    return 0;
}
