/*!
 *   @file utilities.hpp
 *   @brief Definição de funções utilizadas no main e nos menus
 *   @date 01 de maio de 2023
 *   @author Beatriz G. Gadelha
 */

#include "Lista.hpp"
#include "Playlist.hpp"

/*!
    Essa função cria uma Lista<Musica> para ser a base inicial das músicas e a retorna.

    @return Uma lista de músicas formatada com as músicas iniciais configuradas
*/
Lista<Musica> *configuracaoInicialMusicas();

/*!
    Essa função cria uma Lista<Playlist> para ser a base inicial das playlists,
    tomando como parâmetro a base de músicas configuradas anteriormente e a retorna.

    @param baseMusicas Iterador para a base de músicas principal
    @return Uma lista de playlists formatada com as playlists iniciais configuradas
*/
Lista<Playlist> *configuracaoInicialPlaylists(Lista<Musica> *baseMusicas);

void lerMusicasDeArquivo(string path, Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

/*!
    Esta função trata do menu principal da nossa aplicação com opções para
    gerenciar músicas, gerenciar playlists, gerenciar as músicas em playlists,
    tocar músicas ou sair

    @param baseMusicas Iterador para a base de músicas principal
    @param basePlaylists Iterador para a base de playlists principal
*/
void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

/*!
    Esta função trata do menu de músicas da nossa aplicação com opções para
    adicionar músicas, remover músicas, listar todas as músicas da base ou
    retornar ao menu principal

    @param baseMusicas Iterador para a base de músicas principal
    @param basePlaylists Iterador para a base de playlists principal
*/
void menuMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

/*!
    Esta função trata do menu de playlists da nossa aplicação com opções para
    adicionar playlists, remover playlists, listar todas as playlists da base,
    gerenciar as músicas de uma playlist ou retornar ao menu principal

    @param baseMusicas Iterador para a base de músicas principal
    @param basePlaylists Iterador para a base de playlists principal
*/
void menuPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

/*!
    Esta função trata do menu de gereciamento de músicas de uma playlist da nossa
    aplicação com opções para adicionar música na playlists, remover música da playlists,
    listar todas as música na playlists da base ou retornar ao menu anterior

    @param baseMusicas Iterador para a base de músicas principal
    @param basePlaylists Iterador para a base de playlists principal
*/
void menuMusicasEmPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

/*!
    Esta função trata do menu da fila de reprodução de uma playlist da nossa
    aplicação que além de indicacr a música que está tocando possui as opções
    para avançar para a próxima música, retornar para a música anterior ou
    retornar ao menu anterior

    @param baseMusicas Iterador para a base de músicas principal
    @param basePlaylists Iterador para a base de playlists principal
*/
void menuTocarMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

/*!
    Esta função trata do menu da listagem de músicas da nossa aplicação que
    recebe uma lista de músicas e imprimi todas as músicas dela

    @param baseMusicas Iterador para a base de músicas a ser listada
*/
void menuListagemMusicas(Lista<Musica> *baseMusicas);

/*!
    Esta função trata do menu da listagem de playlists da nossa aplicação que
    recebe uma lista de playlists e imprimi cada uma delas com suas músicas

    @param basePlaylists Iterador para a base de playlists a ser listada
*/
void menuListagemPlaylists(Lista<Playlist> *basePlaylists);

/*!
    Esta função trata do menu das funções extras implementadas da nossa aplicação
    @param basePlaylists Iterador para a base de playlists principal
    @param baseMusicas Iterador para a base de musicas principal
*/
void menuExtras(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

/*!
    Esta função serve para tratar a entrada recebido dos menus, ela lê a entrada
    e a formata para o variáveel do tipo inteiro informada

    @param acao Iterador para a variável a ser salvo o valor tratado
*/
void tratarAcao(int *acao);

/*!
    Esta função recebe uma string e retorna se o seu conteúdo trata-se de um número
    ou não

    @param entry Valor a ser testado
    @return Booleano informando se o valor é um número ou não
*/
bool isNumber(string entry);
