#include "utilities.hpp"

#include <iostream>

void menuPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
  while (true)
  {
    string entry;
    int acao = -1;
    Playlist p;

    cout << "\nMENU PLAYLISTS\n";
    cout << "1 - Adicionar playlist\n2 - Remover playlist\n3 - Listar playlists\n4 - Gerenciar Músicas em Playlists\n5 - Sair\n";
    cout << "Digite a opção da sua ação: ";
    tratarAcao(&acao);
    if (acao == -1)
    {
      continue;
    }

    switch (acao)
    {
    case 1:
      cout << "Digite o nome da playlist: ";
      getline(cin, entry);
      p.setNome(entry);

      if (basePlaylists->buscar(p) != nullptr)
      {
        cout << "\nPlaylist já existente!\n\n";
        break;
      }
      basePlaylists->inserir(p);
      cout << "\nPlaylist Cadastrada!\n\n";
      break;
    case 2:
    {
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);
      cout << "Digite o número da playlist a ser removida: ";
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }

      No<Playlist> *p2 = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p2 = p2->getProximo();
        if (p2 == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      basePlaylists->remover(p2->getValor());
      cout << "\nPlaylist removida!\n\n";
      break;
    }
    case 3:
    {
      menuListagemPlaylists(basePlaylists);
      break;
    }
    case 4:
      menuMusicasEmPlaylists(baseMusicas, basePlaylists);
      break;
    case 5:
      return;
    default:
      cout << "Opção inválida!\n";
      break;
    }
  }
}
