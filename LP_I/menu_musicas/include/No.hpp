#ifndef NO_H
#define NO_H

/*!
 *   @file No.hpp
 *   @brief Definição da classe No
 *   @date 01 de maio de 2023
 *   @author Rodrigo Barbalho
 */

using namespace std;

/// @class No No.hpp "include/No.hpp"
/// @brief Implementação de uma classe No
/// @param T Variável template
template <class T>
class No
{
private:
  /// @brief Valor do nó
  T valor;
  /// @brief Iterador para o próximo nó
  No<T> *proximo;

public:
  /// @brief Construtor padrão da classe
  /// @param NULL
  No() : proximo(nullptr){}

  /// @brief Construtor que inicializa o nó com um valor
  /// @param valor Valor com que o nó será iniciado
  No(T valor) : valor(valor), proximo(nullptr){}

  /// @brief Função para configurar o valor do nó
  /// @param valor Valor que será atribuído ao nó
  void setValor(T valor){
    this->valor = valor;
  }

  /// @brief Função para configurar o próximo nó
  /// @param proximo Iterador para o próximo nó
  void setProximo(No<T> *proximo){
    this->proximo = proximo;
  }

  /// @brief Função que retorna o valor do nó
  /// @return Valor do nó
  T getValor() const{
    return valor;
  }

  /// @brief Função que retorna o próximo nó
  /// @return Iterador para o próximo nó
  No<T> *getProximo() const{
    return proximo;
  }
};

#endif // NO_HPP