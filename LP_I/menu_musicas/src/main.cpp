#include <iostream>

#include "utilities.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Lista<Musica> *musicas = configuracaoInicialMusicas();
    Lista<Playlist> *playlists = configuracaoInicialPlaylists(musicas);

    if (argc > 1)
        lerMusicasDeArquivo(argv[1], musicas, playlists);

    menuPrincipal(musicas, playlists);

    delete musicas;
    delete playlists;

    return 0;
}