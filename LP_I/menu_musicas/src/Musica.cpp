#include "Musica.hpp"

#include <ostream>

Musica::Musica() {}

Musica::Musica(const string &titulo, const string &artista)
               : titulo(titulo), artista(artista){}

Musica::~Musica() {}

void Musica::setTitulo(const string &titulo)
{
  this->titulo = titulo;
}

void Musica::setArtista(const string &artista)
{
  this->artista = artista;
}

string Musica::getTitulo() const {
  return titulo;
}

string Musica::getArtista() const {
  return artista;
}

bool Musica::operator==(const Musica &musica) const
{
  return titulo == musica.titulo && artista == musica.artista;
}

ostream &operator<<(ostream &cout, const Musica &m)
{
  cout << m.artista << " - " << m.titulo << endl;

  return cout;
}
