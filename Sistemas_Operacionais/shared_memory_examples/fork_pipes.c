#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    int vetor_pipe[2], TAM; // 0 para leitura e 1 para escrita

    TAM = strlen(argv[1]) + 1;
    char buffer[TAM];

    pipe(vetor_pipe); // Criação do pipe
    pid = fork(); //Criação do novo processo

    if(pid == 0)
    {
        close(vetor_pipe[1]); // Fecha o caminho de escrita
        while (read(vetor_pipe[0], &buffer, TAM) > 0) // Lê enquanto não for EOF
        close(vetor_pipe[0]); //Fecha o camiclnho de leitura
        printf("FILHO: O filho terminou e leu: %s\n", buffer);
        exit(EXIT_SUCCESS);        
    }
    else
    {
        close(vetor_pipe[0]); // Fecha o caminho de leitura
        sleep(2);
        write( vetor_pipe[1], argv[1], strlen(argv[1]) + 1);  // Escreve o conteúdo do argv
        close(vetor_pipe[1]); // Fecha o caminho de escrita (EOF)
        printf("PAI: O pai terminou e escreveu: %s\n", argv[1]);
        wait(NULL); // Espera até que o filho termine
        printf("PAI: O filho terminou\n");
        exit(EXIT_SUCCESS);

    }

    return 0;
}
