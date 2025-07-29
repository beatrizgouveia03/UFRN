#include "utilities.hpp"

#include <iostream>

void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
  while (true)
  {
    int acao = -1;

    cout << "\nMENU PRICIPAL\n";
    cout << "1 - Gerenciar Músicas\n2 - Gerenciar Playlists\n3 - Gerenciar Músicas em Playlists\n";
    cout << "4 - Tocar músicas\n5 - Menu Extra\n6 - Sair\n";
    cout << "Digite a opção da sua ação: ";
    tratarAcao(&acao);
    if (acao == -1)
    {
      continue;
    }

    switch (acao)
    {
    case 1:
      menuMusicas(baseMusicas, basePlaylists);
      break;
    case 2:
      menuPlaylists(baseMusicas, basePlaylists);
      break;
    case 3:
      menuMusicasEmPlaylists(baseMusicas, basePlaylists);
      break;
    case 4:
      menuTocarMusicas(baseMusicas, basePlaylists);
      break;
    case 5:
      menuExtras(baseMusicas, basePlaylists);
      break;
    case 6:
      return;
    default:
      cout << "Opção inválida\n\n";
      break;
    }
  }
}