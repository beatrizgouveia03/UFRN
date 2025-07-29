Pasta dedicada a Side Quest #04 (lista sobre busca binária)
Feita por: Beatriz Gouveia Gadelha

Questões respondidas:
01 - local_minimum_in_an_array
08 - find_a_duplicate
11 - longest_row_of_zeros
12 - sum_of_two
14 - find_the_duplicate

Como compilar:
Este projeto pode ser compilado com CMake (https://cmake.org). CMake é uma família de ferramentas multiplataforma de código aberto projetada para criar, 
testar e empacotar software. Basicamente, o cmake lê um script (`CMakeLists.txt`) com meta-informações sobre o projeto e **cria um Makefile automaticamente**, 
adaptado à configuração do seu sistema.
Depois disso, você pode executar o comando `make`, como de costume. 
Para compilar esse projeto, é necessário primeiro você entrar na pasta da questão a ser compilada digitando `cd question_X`, onde X é o número da questão.
Em seguida, dentro da pasta principal da questão é necessário criar uma pasta `build` para armazenar todos os arquivops criados pelo CMake, digitando `mkdir build`
Por fim, basta acessar essa pasta e utilizar os comando do CMake, sendo assim: `cd build`, `cmake ..` e `make`.
Após isso, já terá sido gerado um executável nomeado `program` dentro da pasta `build`.

Como rodar o projeto:
Uma vez que foi criado o executável da questão a ser testada, basta rodar o comando `./program`, caso você esteja ainda na pasta `build`.
Ou `./build/program`, caso esteja na pasta principal da questão.
E será possível observar no terminal, os resultados dos teste implementados.
