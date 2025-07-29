#ifndef LISTA_H
#define LISTA_H

/*!
 *   @file Lista.hpp
 *   @brief Definição da classe Lista
 *   @date 01 de maio de 2023
 *   @author Beatriz G. Gadelha
 */

#include <iostream>

#include "No.hpp"

using namespace std;

/// @class Lista Lista.hpp "include/Lista.hpp"
/// @brief Implementação de uma classe Lista
/// @param T Variável template
template <class T>
class Lista
{
private:
  /// @brief Iterador para indicar o head/início da lista
  No<T> *cabeca;
  /// @brief Iterador para indicar o tail/cauda da lista
  No<T> *cauda;

public:
  /// @brief Construtor padrão da classe
  /// @param NULL
  Lista() : cabeca(nullptr), cauda(nullptr){}

  /// @brief Construtor que inicializa a lista com um nó
  /// @param valor Valor com que o nó será iniciado
  Lista(T valor){
    cabeca = new No<T>(valor);
    cauda = cabeca;
  }

  /// @brief Construtor cópia
  /// @param lista Lista com os elementos que serão inicializados na lista
  Lista(const Lista<T> &lista) : cabeca(nullptr), cauda(nullptr){
    No<T> *atual = lista.cabeca;

    while(atual != nullptr){
      inserir(atual->getValor());
      atual = atual->getProximo();
    }
  }

  /// @brief Destrutor padrão da classe
  /// @param NULL
  ~Lista(){
    No<T> *atual = cabeca;

    while(atual != nullptr){
      No<T> *proximo = atual->getProximo();
      delete atual;
      atual = proximo;
    }
  }

  /// @brief Função para configurar o head/cabeça da lista
  /// @param cabeca Iterador para o nó que será a cabeça da lista
  void setCabeca(No<T> *cabeca){
    if(cabeca != nullptr) delete this->cabeca;
    this->cabeca = cabeca;
  }

  /// @brief Função para configurar o tail/cauda da lista
  /// @param cauda Iterador para o nó que será a cauda da lista
  void setCauda(No<T> *cauda){
    if (cauda != nullptr) delete this->cauda;
    this->cauda = cauda;
  }

  /// @brief Função que retorna um ponteiro indicando o head/cabeça da lista
  /// @return Iterador para a cabeça da lista
  No<T> *getCabeca() const {
    return cabeca;
  }
  /// @brief Função que retorna um ponteiro indicando o tail/cauda da lista
  /// @return Iterador para a cauda da lista
  No<T> *getCauda() const {
    return cauda;
  }

  /// @brief Função para inserir um elemento na lista
  /// @param valor Valor que será inserido no novo fim da lista
  void inserir(T valor){
    No<T> *novo = new No<T>(valor);

    if(cabeca == nullptr){
      cabeca = novo;
      cauda = cabeca;
    } else {
      cauda->setProximo(novo);
      cauda = novo;
    }
  }

  /// @brief Função para inserir todos os elemeneos de outra lista na lista
  /// @param lista Lista com os elementos a serem adicionados
  void adicionarElementos(const Lista<T>& lista){
    No<T>* atual = lista.cabeca;

    while (atual != nullptr)
    {
      inserir(atual->getValor());
      atual = atual->getProximo();
    }
  }

  /// @brief Função para excluir um elemento da lista
  /// @param valor Valor que será removido da lista
  void remover(T valor){
    if (cabeca == nullptr)
    {
      return;
    }

    if (cabeca->getValor() == valor)
    {
      No<T> *temp = cabeca;
      cabeca = cabeca->getProximo();
      delete temp;
      return;
    }

    No<T> *atual = cabeca->getProximo();
    No<T> *anterior = cabeca;

    while (atual != nullptr)
    {
      if (atual->getValor() == valor){
        anterior->setProximo(atual->getProximo());
        delete atual;
        return;
      }

      anterior = atual;
      atual = atual->getProximo();
    }  
  }
  
  void removerElementos(const Lista<T>& lista){
    No<T> *atual = lista.cabeca;

    while(atual != nullptr){
      remover(atual->getValor());
      atual = atual->getProximo();
    }
  }

  /// @brief Função que returna o tamanho da lista
  /// @return Tamanho da lista
  int tamanho() const{
    int tamanho = 0;
    No<T> *atual = cabeca;

    while(atual != nullptr){
      tamanho++;
      atual = atual->getProximo();
    }

    return tamanho;
  }

    /// @brief Função que busca um elemento na lista. Caso o encontre retorna um ponteiro para ele, caso não, retorna um nullptr
    /// @param valor Valor do elemento a ser procurado na lista
    /// @return Interador para o elemento ou nullptr
    No<T> *buscar(T valor) const {
      No<T> *atual = cabeca;

      while (atual != nullptr)
      {
        if(atual->getValor() == valor){
          return atual;
        }

        atual = atual->getProximo();
      }

      return nullptr;
    }

    /// @brief Função que busca se existe um elemento na lista no índice indicado. Caso exista, retorna um ponteiro para ele, cano nãõ~retorna um nullptr
    /// @param indice Indice do elemento a ser procurado na lista
    /// @return Interador para o elemento ou nullptr
    No<T> *buscarPorIndice(int indice) const {
      No<T> *atual = cabeca;

      for(int i=0; i<indice; ++i){
        atual = atual->getProximo();
        if(atual == nullptr) break;
      }

      return atual;
    }

    /// @brief Sobrecarga do operador para adição de listas
    /// @param lista Outra lista que será somada
    /// @return Uma nova lista resultante da soma
  Lista<T> operator+(const Lista<T> &lista) const
  {
    Lista<T> novaLista(*this);

    novaLista.adicionarElementos(lista);

    return novaLista;
  }

  /// @brief Sobrecarga do operador para subtração de listas
  /// @param lista Outra lista que será subtraída
  /// @return Uma nova lista resultante da substração
  Lista<T> operator-(const Lista<T> &lista) const
  {
    Lista<T> novaLista(*this);

    novaLista.removerElementos(lista);

    return novaLista;
 }

  /// @brief Sobrecarga do operador para extração do último nó de uma lista
  /// @param lista Lista da qual será extraído o nó
  /// @param no Nó que será preenchido com o nó extraído da lista
  friend void operator>>(Lista<T> *lista, No<T> &no)
  {
      no.setValor(lista->getCauda()->getValor());
      lista->remover(lista->getCauda()->getValor());
  }

  /// @brief Sobrecarga do operador para inserção de um nó em uma lista
  /// @param lista Lista em que será inserido o nó
  /// @param no Nó que será inserido na lista
  friend void operator<<(Lista<T> *lista, T &valor) {
    lista->inserir(valor);
  }
};

#endif // LISTA_HPP