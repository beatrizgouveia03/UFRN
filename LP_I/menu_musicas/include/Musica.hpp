#ifndef MUSICA_HPP
#define MUSICA_HPP

/*!
 *   @file Musica.hpp
 *   @brief Definição da classe Musica
 *   @date 01 de maio de 2023
 *   @author Beatriz G. Gadelha
 */

#include <string>

using namespace std;

/// @class Musica Musica.hpp "include/Musica.hpp"
/// @brief implementação de uma classe Musica
class Musica
{
private:
  /// @brief Nome da música
  string titulo;
  /// @brief Nome do artista da música
  string artista;

public:
  /// @brief Construtor padrão da classe
  /// @param NULL
  Musica();

  /// @brief Construtor que inicializa a música com seu nome e artista
  /// @param titulo Nome da música
  /// @param artista Nome do artista da música
  Musica(const string &titulo, const string &artista);

  /// @brief Destrutor padrão da classe
  /// @param NULL
  ~Musica();

  /// @brief Função para configurar o nome da música
  /// @param titulo Nome da música
  void setTitulo(const string &titulo);

  /// @brief Função para configurar o nome do artista da múśica
  /// @param artista Nome do artista
  void setArtista(const string &artista);

  /// @brief Função que retorna o nome da música
  /// @return Nome da música
  string getTitulo() const;

  /// @brief Função que retorna o nome do artista da música
  /// @return Nome do artista
  string getArtista() const;

  /// @brief Sobrecarga do operador == para a classe,
  /// permitindo a comparação entre músicas
  /// @param musica Elemento a ser comparado
  /// @return Booleano indicando se as músicas são iguais ou não
  bool operator==(const Musica &musica) const;

  /// @brief Sobrecarga do operator << para a classe,
  /// permitindo a impressão de uma música
  /// @param cout Stream de saída padrão
  /// @param m Elemento a ser impresso
  /// @return Formatação que será impressa a música
  friend ostream &operator<<(ostream &cout, const Musica &m);
};

#endif // MUSICA_HPP