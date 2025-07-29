#include "utilities.hpp"

#include <iostream>








void menuTocarMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        int acao = -1;

        menuListagemPlaylists(basePlaylists);

        cout << "Digite o número da playlist: (digite 0 para sair) " << endl;
        tratarAcao(&acao);
        if (acao == -1)
        {
            continue;
        }
        else if (acao == 0)
        {
            return;
        }

        No<Playlist> *p = basePlaylists->getCabeca();

        while (acao > 1)
        {
            p = p->getProximo();
            if (p == nullptr)
            {
                cout << "\nNão existe nenhuma playlist com este número!\n\n";
                return;
            }
            acao--;
        }

        bool sair = false;

        int indiceMusica = 0;

        while (indiceMusica < p->getValor().getMusicas()->tamanho())
        {

            Musica musicaAtual = p->getValor().getMusicas()->buscarPorIndice(indiceMusica)->getValor();

            cout << "\nTocando: " << musicaAtual.getArtista() << " - " << musicaAtual.getTitulo() << endl;
            if (indiceMusica < p->getValor().getMusicas()->tamanho() - 1)
                cout << "1 - Próxima" << endl;
            if (indiceMusica > 0)
                cout << "2 - Anterior" << endl;
            cout << "Para sair, digite 0" << endl;
            cout << "Digite a opção da sua ação: ";
            tratarAcao(&acao);
            if (acao == -1)
            {
                continue;
            }
            else if (acao == 1 && indiceMusica == p->getValor().getMusicas()->tamanho() - 1)
            {
                acao = 3;
            }
            else if (acao == 2 && indiceMusica == 0)
            {
                acao = 3;
            }

            switch (acao)
            {
            case 1:
                indiceMusica++;
                break;
            case 2:
                indiceMusica--;
                break;
            case 0:
                sair = true;
                return;
            default:
                cout << "Opção inválida!\n";
                break;
            }
        }
    }
}