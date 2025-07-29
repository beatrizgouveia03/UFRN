#ifndef PLAYLIST_H
#define PLAYLIST_H

/*!
 *   @file Playlist.hpp
 *   @brief Definição da classe Playlist
 *   @date 01 de maio de 2023
 *   @author Rodrigo Barbalho
 */

#include "Musica.hpp"
#include "Lista.hpp"

/// @class Playlist Playlist.hpp "include/Playlist.hpp"
/// @brief Implementação de uma classe Playlist
class Playlist
{
private:
  /// @brief Nome da playlist
  string nome;
  /// @brief Lista de músicas da playlist
  Lista<Musica> *musicas;

public:
  /// @brief Construtor padrão da classe
  /// @param NULL
  Playlist();

  /// @brief Construtor que inicializa a playlist com um nome
  /// @param nome Nome da playlist
  Playlist(const string &nome);

  /// @brief Construtor que inicializa a playlist com um nome e uma lista de músicas
  /// @param nome Nome da playlist
  /// @param musicas Lista de músicas da playlist
  Playlist(const string &nome, const Lista<Musica> &musicas);

  /// @brief Construtor cópia da classe
  /// @param playlist Playlist que será copiada
  Playlist(const Playlist &playlist);

  /// @brief Destrutor da classe
  /// @param NULL
  ~Playlist();

  /// @brief Função para configurar o nome da playlist
  /// @param nome Nome que será atribuído à playlist
  void setNome(const string &nome);

  /// @brief Função para configurar a lista de músicas da playlist
  /// @param musicas Lista de músicas que será atribuída à playlist
  void setMusicas(const Lista<Musica> &musicas);

  /// @brief Função que retorna o nome da playlist
  /// @return Nome da playlist
  string getNome() const;

  /// @brief Função que retorna a lista de músicas da playlist
  /// @return Lista de músicas da playlist
  Lista<Musica> *getMusicas() const;

  /// @brief Função para adicionar uma música à playlist
  /// @param m Música que será adicionada à playlist
  void addMusica(const Musica &musica);

  /// @brief Função para adicionar todas as músicas de outra playlist à playlist
  /// @param playlist Playlist que possui a lista de músicas a serem adicionadas
  void addMusica(const Playlist &playlist);

  /// @brief Função para remover uma música da playlist
  /// @param m Música que será removida da playlist
  void remMusica(const Musica &musica);

  /// @brief Função para remover todas as músicas de outra playlist da playlist
  /// @param playlist Playlist que possui a lista de músicas a serem removidas
  void remMusica(const Playlist &playlist);

  /// @brief Função para encontrar uma música na playlist
  /// @param m Música que será procurada na playlist
  /// @return Iterador para a música encontrada
  No<Musica> *findMusica(const Musica &musica) const;

  /// @brief Sobrecarga do operador de comparação
  /// @param playlist Playlist que será comparada
  /// @return True se as playlists forem iguais e false caso contrário
  bool operator==(const Playlist &playlist);

  /// @brief Sobrecarga do operador de saída para printar uma playlist
  /// @param playlist Playlist que será printada
  /// @return Saída(cout) formatada
  friend ostream &operator<<(ostream &cout, const Playlist &playlist);

  /// @brief Sobrecarga do operador para adição de playlists
  /// @param playlist Outra playlist que será somada  
  /// @return Uma nova playlist resultante da soma
  Playlist *operator+(const Playlist &playlist);

  /// @brief Sobrecarga do operador para adição de uma musica em uma playlist
  /// @param musica Musica que será adicionada na playlist
  /// @return Uma nova playlist resultante da soma
  Playlist *operator+(const Musica &musica);

  /// @brief Sobrecarga do operador para subtração entre playlists
  /// @param playlist Outra playlist que será subtraída
  /// @return Uma nova playlist resultante da subtração
  Playlist *operator-(const Playlist &playlist);

  /// @brief Sobrecarga do operador para subtração de uma musica em uma playlist
  /// @param musica Musica que será subtraída na playlist
  /// @return Uma nova playlist resultante da subtração
  Playlist *operator-(const Musica &musica);

  /// @brief Sobrecarga do operador para extração da última musica de uma playlist
  /// @param playlist Playlist da qual será extraída a música
  /// @param musica Musica que será preenchida com a música extraída na playlist
  friend void operator>>(Playlist *playlist, Musica &musica);

  /// @brief Sobrecarga do operador para inserção de uma musica em uma playlist
  /// @param playlist Playlist daa qual será inserida a música
  /// @param musica Musica que será inserida na playlist
  friend void operator<<(Playlist *playlist, Musica &musica);
};

#endif // PLAYLIST_H