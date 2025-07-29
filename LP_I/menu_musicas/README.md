# Menu de Músicas

Este é um projeto de um menu de músicas criado em C++. O objetivo deste projeto é permitir que os usuários possam visualizar listas de músicas e de Playlist e selecionar a que desejam ouvir.

## Funcionalidades

- Listar todas as músicas disponíveis
- Adicionar uma nova música à lista
- Remover uma música da lista
- Criar uma nova playlist
- Excluir uma playlist
- Adicionar músicas a uma playlist
- Remover músicas de uma playlist
- Listar todas as playlists disponíveis
- Selecionar uma playlist para reproduzir

## Requisitos

Para executar o projeto, é necessário ter o compilador C++ instalado na sua máquina. Recomenda-se o uso do compilador GCC.

Também é possível executar o projeto com o CMake. Para isso, é necessário ter o CMake instalado na sua máquina.

## Como executar com o GCC

Para executar o projeto com o GCC, siga as instruções abaixo:

1. Clone o repositório do projeto para a sua máquina local:

```
git clone git clone https://github.com/beatrizgouveia03/LP_I.git --branch main --single-branch menu_musicas
```

2. Abra o terminal na pasta onde o repositório foi clonado e compile o código-fonte usando o seguinte comando:

```
g++ -o menu_musicas main.cpp menus.cpp Musica.cpp Playlist.cpp utilities.cpp
```

3. Execute o programa com o seguinte comando:

```
./menu_musicas
```

## Como executar com o CMake

Para executar o projeto com o CMake, siga as instruções abaixo:

1. Clone o repositório do projeto para a sua máquina local:

```
git clone git clone https://github.com/beatrizgouveia03/LP_I.git --branch main --single-branch menu_musicas
```

2. Abra o terminal na pasta onde o repositório foi clonado e crie uma nova pasta chamada "build":

```
mkdir build
cd build
```

3. Execute o CMake com o seguinte comando:

```
cmake ..
```

4. Execute o comando make para compilar o código:

```
make
```

5. Execute o programa com o seguinte comando:

```
./menu_musicas
```

## Documentação

A documentação do projeto foi gerada com o Doxygen.

## Contribuindo

Se você deseja contribuir com este projeto, siga as instruções abaixo:

1. Faça um fork deste repositório para a sua conta no GitHub
2. Clone o repositório do seu fork na sua máquina local
3. Crie uma nova branch para a sua contribuição:

```
git checkout -b minha-contribuicao
```

4. Adicione suas alterações ao código e documentação
5. Faça um commit das suas alterações:

```
git add .
git commit -m "Minha contribuição"
```

6. Envie as suas alterações para o GitHub:

```
git push origin minha-contribuicao
```

7. Abra um pull request no repositório original para que suas alterações possam ser revisadas e incorporadas.

# Contribuidores

1. Beatriz Gouveia Gadelha
2. Rodrigo Eduardo Dantas Barbalho
