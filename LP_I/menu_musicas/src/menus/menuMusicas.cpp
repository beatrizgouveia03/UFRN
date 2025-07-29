#include "utilities.hpp"

#include <iostream>

void menuMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylist)
{
  while (true)
  {
    int acao = -1;
    string entry;
    Musica m;

    cout << "\nMENU MÚSICAS\n";
    cout << "1 - Adicionar música\n2 - Remover música\n3 - Listar músicas\n4 - Sair\n";
    cout << "Digite a opção da sua ação: ";
    tratarAcao(&acao);
    if (acao == -1)
    {
      continue;
    }

    switch (acao)
    {
    case 1:
      cout << "Digite o nome da música: ";
      getline(cin, entry);
      m.setTitulo(entry);

      cout << "Digite o artista da música: ";
      getline(cin, entry);
      m.setArtista(entry);

      if (baseMusicas->buscar(m) != nullptr)
      {
        cout << "\nMúsica já existe na lista!\n";
        break;
      }

      baseMusicas->inserir(m);
      cout << "\nMúsica Cadastrada!\n\n";

      break;
    case 2:
    {
      int acao2 = -1;
      menuListagemMusicas(baseMusicas);

      cout << "Digite o número da música: " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }

      No<Musica> *m = baseMusicas->getCabeca();

      while (acao2 > 1)
      {
        m = m->getProximo();
        if (m == nullptr)
        {
          cout << "\nNão existe nenhuma música com este número!\n\n";
          return;
        }
        acao2--;
      }

      No<Playlist> *p = basePlaylist->getCabeca();

      while (p != nullptr)
      {
        Playlist p2 = p->getValor();

        if (p2.findMusica(m->getValor()) != nullptr)
        {
          p->getValor().remMusica(m->getValor());
        }
        p = p->getProximo();
      }

      baseMusicas->remover(m->getValor());

      cout << "\nMúsica removida!\n\n";
      break;
    }
    case 3:
    {
      menuListagemMusicas(baseMusicas);
      break;
    }
    case 4:
      return;
    default:
      cout << "Opção inválida!\n";
      break;
    }
  }
}