#include "utilities.hpp"

#include <fstream>

using namespace std;

Lista<Musica> *configuracaoInicialMusicas()
{
  string titulo[] = {"I'm good", "I'm believer", "I want it that way", "Alejandro", "Applause", "Californication"};
  string artista[] = {"David Guetta", "Smash Mounth", "Backstreet Boys", "Lady Gaga", "Lady Gaga", "Red Hot Chili Peppers"};

  Lista<Musica> *baseMusicas = new Lista<Musica>();

  for (int i = 0; i < 6; i++)
  {
    Musica musica;
    musica.setTitulo(titulo[i]);
    musica.setArtista(artista[i]);

    baseMusicas->inserir(musica);
  }

  return baseMusicas;
}

Lista<Playlist> *configuracaoInicialPlaylists(Lista<Musica> *baseMusicas)
{
  Lista<Playlist> *basePlaylists = new Lista<Playlist>();

  Lista<Musica> *musicasPlaylist1 = new Lista<Musica>();
  Lista<Musica> *musicasPlaylist2 = new Lista<Musica>();

  auto itr = baseMusicas->getCabeca();
  auto end = baseMusicas->getCauda();

  int index = 0;

  while (itr != nullptr)
  {
    if (index % 2 == 0)
    {
      musicasPlaylist1->inserir(itr->getValor());
    }
    else
    {
      musicasPlaylist2->inserir(itr->getValor());
    }

    itr = itr->getProximo();
    index++;
  }

  Playlist *playlist1 = new Playlist("Top Hits 2002", *musicasPlaylist1);
  Playlist *playlist2 = new Playlist("Good Vibes", *musicasPlaylist2);

  basePlaylists->inserir(*playlist1);
  basePlaylists->inserir(*playlist2);

  delete playlist1;
  delete playlist2;
  delete musicasPlaylist1;
  delete musicasPlaylist2; 

  return basePlaylists;
}

void lerMusicasDeArquivo(string path, Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
  if (path.empty())
    return;

  ifstream arquivo(path);

  while (!arquivo.eof())
  {
    string linha = "";
    int i = 0;
    string playlistAtual = "";

    getline(arquivo, linha);

    // obter nome da Playlist
    for (; linha[i] != ';'; i++)
    {
      playlistAtual += linha[i];
    }

    i++;

    Lista<Musica> *musicasNovas = new Lista<Musica>();

    while (i < linha.length())
    {
      string musicaAtual = "";
      string artistaAtual = "";

      // obter nome de Musica
      for (; linha[i] != ':'; i++)
      {
        musicaAtual += linha[i];
      }

      i++;

      // obter nome do artista
      for (; linha[i] != ','; i++)
      {
        if (i >= linha.length())
          break;
        artistaAtual += linha[i];
      }

      i++;

      Musica musica(musicaAtual, artistaAtual);

      // ADICIONAR MUSICA A MUSICAS
      musicasNovas->inserir(musica);
    }

    arquivo.close();

    // ADICIONAR PLAYLIST COM MUSICAS
    Playlist playlist(playlistAtual, *musicasNovas);

    baseMusicas->adicionarElementos(*musicasNovas);
    basePlaylists->inserir(playlist);

    delete musicasNovas;
  }
}

void tratarAcao(int *acao)
{
  string entry;

  getline(cin, entry);
  if (!isNumber(entry))
  {
    cout << "Entrada inválida!\n\n";
    return;
  }
  *acao = stoi(entry);

  return;
}

bool isNumber(string entry)
{
  for (size_t i = 0; i < (entry.length() - 1); ++i)
  {
    if (!isdigit(entry[i]))
    {
      return false;
    }
  }

  return true;
}