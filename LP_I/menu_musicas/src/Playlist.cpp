#include "Playlist.hpp"

#include <ostream>

Playlist::Playlist() : nome(""),musicas(nullptr){}

Playlist::Playlist(const string &nome) : nome(nome), musicas(nullptr){}

Playlist::Playlist(const string &nome, const Lista<Musica> &musicas)
                 : nome(nome), musicas(nullptr){
  if (musicas.getCabeca() != nullptr)
  {
    this->musicas = new Lista<Musica>(musicas);
  }
}

Playlist::Playlist(const Playlist &playlist) 
                 : nome(playlist.nome), musicas(nullptr)
{
  if(playlist.musicas != nullptr){
    musicas = new Lista<Musica>(*playlist.musicas);
  }
}

Playlist::~Playlist() {
  delete musicas;
}

void Playlist::setNome(const string &nome)
{
  this->nome = nome;
}

void Playlist::setMusicas(const Lista<Musica> &musicas)
{
  if(this->musicas != nullptr) delete this->musicas;
  this->musicas = new Lista<Musica>(musicas);
}

string Playlist::getNome() const
{
  return nome;
}

Lista<Musica> *Playlist::getMusicas() const
{
  return musicas;
}

void Playlist::addMusica(const Musica &musica)
{
  if(musicas == nullptr){
    musicas = new Lista<Musica>();
  }
  musicas->inserir(musica);
}

void Playlist::addMusica(const Playlist &playlist)
{
  if(musicas == nullptr){
    musicas = new Lista<Musica>();
  }
  musicas->adicionarElementos(*playlist.getMusicas());
}

void Playlist::remMusica(const Musica &musica)
{
  if(musicas != nullptr){
    musicas->remover(musica);
  }
}

void Playlist::remMusica(const Playlist &playlist)
{
  if(musicas != nullptr){
    musicas->removerElementos(*playlist.getMusicas());
  }
}

No<Musica> *Playlist::findMusica(const Musica &musica) const
{
  if(musicas != nullptr){
    return musicas->buscar(musica);
  }

  return nullptr;
}

bool Playlist::operator==(const Playlist &playlist)
{
  if (nome == playlist.getNome())
  {
    return true;
  }

  return false;
}

ostream &operator<<(ostream &cout, const Playlist &playlist)
{
  cout << "Nome: " << playlist.nome << endl;
  cout << "Musicas: " << endl;

  if (playlist.musicas == nullptr)
  {
    cout << "Nenhuma música cadastrada!\n";
    return cout;
  }

  int count = 1;
  No<Musica> *itr = playlist.musicas->getCabeca();

  while (itr != nullptr)
  {
    Musica m = itr->getValor();
    cout << "[" << count << "] " << m;

    itr = itr->getProximo();
    count++;
  }

  return cout;
}

Playlist *Playlist::operator+(const Playlist &playlist)
{
  Playlist *resultado = new Playlist("", *this->musicas);
  
  resultado->addMusica(playlist);

  return resultado;
}

Playlist *Playlist::operator+(const Musica &musica)
{
  Playlist *resultado = new Playlist("", *this->musicas);

  resultado->addMusica(musica);

  return resultado;
}

Playlist *Playlist::operator-(const Playlist &playlist)
{
  Playlist *resultado = new Playlist("", *this->musicas);

  resultado->remMusica(playlist);

  return resultado;
}

Playlist *Playlist::operator-(const Musica &musica)
{
  Playlist *resultado = new Playlist("", *this->musicas);

  resultado->remMusica(musica);

  return resultado;
}

void operator>>(Playlist *playlist, Musica &musica)
{
  No<Musica> extracao;
  playlist->getMusicas() >> extracao;

  musica = extracao.getValor();
}

void operator<<(Playlist *playlist, Musica &musica)
{
  playlist->getMusicas() << musica;
}

