#include "utilities.hpp"

#include <iostream>

void menuExtras(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
  while (true)
  {
    int acao = -1;
    string entry;
    Musica m;

    cout << "\nMENU EXTRAS\n";
    cout << "1 - Extrair última música\n2 - Inserir uma música\n3 - Adicionar uma playlist em outra\n4 - Remover uma playlist de outra\n";
    cout << "5 - Duplicar playlist\n6 - Criar uma união de playlists\n7 - Criar uma diferença de playlists\n";
    cout << "8 - Criar uma união de playlist e música\n9 - Criar uma diferença de playlist e música\n10 - Sair\n";
    cout << "Digite a opção da sua ação: ";
    tratarAcao(&acao);
    if (acao == -1)
    {
      continue;
    }

    switch (acao)
    {
    //Extrair a última música
    case 1:{
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      Playlist play = p->getValor();
      Musica musica;
      &play >> musica;

      cout << "Música extraída: \n" << musica << endl;
      cout << play << endl;
      break;
    }
    //inserir musica
    case 2:
    {
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      int acao3 = -1;
      menuListagemMusicas(baseMusicas);

      cout << "Digite o número da música: " << endl;
      tratarAcao(&acao3);
      if (acao3 == -1)
      {
        continue;
      }

      Playlist play = p->getValor();
      Lista<Musica> *musicas = play.getMusicas();
      No<Musica> *musicaEscolhida = baseMusicas->getCabeca();

      while (acao3 > 1)
      {
        musicaEscolhida = musicaEscolhida->getProximo();
        if (musicaEscolhida == nullptr)
        {
          cout << "\nNão existe nenhuma música com este número!\n\n";
          return;
        }
        acao3--;
      }

      Musica musica = musicaEscolhida->getValor();
      &play << musica;
      cout << "\nMúsica Inserida!\n";
      cout << play << endl;

      p->setValor(play);

      break;
    }
    // Adicionar uma playlist em outra
    case 3:{
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist na qual as músicas serão adicionadas: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      int acao3 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist que será adicionada: (digite 0 para sair) " << endl;
      tratarAcao(&acao3);
      if (acao3 == -1)
      {
        continue;
      }
      else if (acao3 == 0)
      {
        return;
      }

      No<Playlist> *p2 = basePlaylists->getCabeca();

      while (acao3 > 1)
      {
        p2 = p2->getProximo();
        if (p2 == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao3--;
      }

      p->getValor().addMusica(p2->getValor());
      cout << "Playlist " << p2->getValor().getNome() << " adicionada na Playlist " << p->getValor().getNome() << "\n";
      cout << p->getValor();

      break;
    }
    // Remover uma playlist de outra
    case 4:
    {
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist na qual as músicas serão removidas: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      int acao3 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist que será removida: (digite 0 para sair) " << endl;
      tratarAcao(&acao3);
      if (acao3 == -1)
      {
        continue;
      }
      else if (acao3 == 0)
      {
        return;
      }

      No<Playlist> *p2 = basePlaylists->getCabeca();

      while (acao3 > 1)
      {
        p2 = p2->getProximo();
        if (p2 == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao3--;
      }

      p->getValor().addMusica(p2->getValor());
      cout << "Playlist " << p2->getValor().getNome() << " removida aa Playlist " << p->getValor().getNome() << "\n";
      cout << p->getValor();

      break;
    }
    //DUplicar playlist
    case 5:
    {
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist a ser duplicada: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      Playlist *novaPlaylist = new Playlist(p->getValor());
      basePlaylists->inserir(*novaPlaylist);

      delete novaPlaylist;

      if(basePlaylists->getCauda()->getValor() == p->getValor()){
        cout << "Playlist duplicada!\n";
        menuListagemPlaylists(basePlaylists);
      }

      break;
    }
    // Criar uma união de playlists
    case 6:
    {
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da primeira playlist da união: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      int acao3 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da segunda playlist da união: (digite 0 para sair) " << endl;
      tratarAcao(&acao3);
      if (acao3 == -1)
      {
        continue;
      }
      else if (acao3 == 0)
      {
        return;
      }

      No<Playlist> *p2 = basePlaylists->getCabeca();

      while (acao3 > 1)
      {
        p2 = p2->getProximo();
        if (p2 == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao3--;
      }

      Playlist *novaPlaylist = p->getValor()+p2->getValor();
      novaPlaylist->setNome("União");
      basePlaylists->inserir(*novaPlaylist);

      cout << "Playlists unidas\n";
      menuListagemPlaylists(basePlaylists);

      delete novaPlaylist;

      break;
    }
    // Criar uma diferença de playlists
    case 7:
    {
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da primeira playlist da diferença: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      int acao3 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da segunda playlist da diferença: (digite 0 para sair) " << endl;
      tratarAcao(&acao3);
      if (acao3 == -1)
      {
        continue;
      }
      else if (acao3 == 0)
      {
        return;
      }

      No<Playlist> *p2 = basePlaylists->getCabeca();

      while (acao3 > 1)
      {
        p2 = p2->getProximo();
        if (p2 == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao3--;
      }

      Playlist *novaPlaylist = p->getValor() - p2->getValor();
      novaPlaylist->setNome("Diferença");
      basePlaylists->inserir(*novaPlaylist);

      delete novaPlaylist;

      cout << "Playlists diferenciadas\n";
      menuListagemPlaylists(basePlaylists);

      break;
    }
    // Criar uma união de playlist e música
    case 8:
    {
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      int acao3 = -1;
      menuListagemMusicas(baseMusicas);

      cout << "Digite o número da música: " << endl;
      tratarAcao(&acao3);
      if (acao3 == -1)
      {
        continue;
      }

      Playlist play = p->getValor();
      Lista<Musica> *musicas = play.getMusicas();
      No<Musica> *musicaEscolhida = baseMusicas->getCabeca();

      while (acao3 > 1)
      {
        musicaEscolhida = musicaEscolhida->getProximo();
        if (musicaEscolhida == nullptr)
        {
          cout << "\nNão existe nenhuma música com este número!\n\n";
          return;
        }
        acao3--;
      }

      Musica musica = musicaEscolhida->getValor();
      Playlist *novaPlaylist = p->getValor() + musica;
      novaPlaylist->setNome("Soma playlist e música");
      basePlaylists->inserir(*novaPlaylist);

      cout << "PLaylist somada com música!\n";
      menuListagemPlaylists(basePlaylists);

      delete novaPlaylist;

      break;
    }
    // Criar uma diferença de playlists
    case 9:
    {
      int acao2 = -1;

      menuListagemPlaylists(basePlaylists);

      cout << "Digite o número da playlist: (digite 0 para sair) " << endl;
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }
      else if (acao2 == 0)
      {
        return;
      }

      No<Playlist> *p = basePlaylists->getCabeca();

      while (acao2 > 1)
      {
        p = p->getProximo();
        if (p == nullptr)
        {
          cout << "\nNão existe nenhuma playlist com este número!\n\n";
          return;
        }
        acao2--;
      }

      int acao3 = -1;
      menuListagemMusicas(baseMusicas);

      cout << "Digite o número da música: " << endl;
      tratarAcao(&acao3);
      if (acao3 == -1)
      {
        continue;
      }

      Playlist play = p->getValor();
      Lista<Musica> *musicas = play.getMusicas();
      No<Musica> *musicaEscolhida = baseMusicas->getCabeca();

      while (acao3 > 1)
      {
        musicaEscolhida = musicaEscolhida->getProximo();
        if (musicaEscolhida == nullptr)
        {
          cout << "\nNão existe nenhuma música com este número!\n\n";
          return;
        }
        acao3--;
      }

      Musica musica = musicaEscolhida->getValor();
      Playlist *novaPlaylist = p->getValor() - musica;
      novaPlaylist->setNome("Diferença playlist e música");
      basePlaylists->inserir(*novaPlaylist);

      cout << "PLaylist diferenciada com música!\n";
      menuListagemPlaylists(basePlaylists);

      delete novaPlaylist;

      break;
    }
    case 10:
      return;
    default:
      cout << "Opção inválida!\n";
      break;
    }
  }
}