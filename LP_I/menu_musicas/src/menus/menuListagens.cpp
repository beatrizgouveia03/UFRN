#include "utilities.hpp"

#include <iostream>

void menuListagemMusicas(Lista<Musica> *baseMusicas)
{
  cout << "\nLISTAGEM DE MÚSICAS\n\n";

  No<Musica> *itr = baseMusicas->getCabeca();

  int count = 1;
  while (itr != nullptr)
  {
    Musica m = itr->getValor();
    cout << "[" << count << "] " << m;

    itr = itr->getProximo();
    count++;
  }
  cout << endl;

  return;
}

void menuListagemPlaylists(Lista<Playlist> *basePlaylists)
{
  cout << "\nLISTAGEM DE PLAYLISTS\n";

  No<Playlist> *itr = basePlaylists->getCabeca();

  int count = 1;
  while (itr != nullptr)
  {
    Playlist p = itr->getValor();

    cout << "-- " << count << " --\n"
         << p << endl;

    itr = itr->getProximo();
    count++;
  }
  cout << endl;

  return;
}