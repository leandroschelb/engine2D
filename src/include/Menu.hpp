#ifndef MENU_HEADER
#define MENU_HEADER

#include <SFML/Graphics.hpp>
#include "../classes/desenhavel/animado/jogador/jogador.hpp"
#include "../classes/desenhavel/animado/inimigo/inimigo.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

/**
 * Classe base para todos os menus do jogo.
 */
class Menu
{
  private:
    bool aberto;
  public:
    sf::RenderWindow* window;
    int coordAtual[2];
    sf::Font roboto;
    int tamTile;
    int numOpcoes;

    /**
     * Construtor de Menu.
     * @param w ponteiro para instância de janela de SFML.
     * @param tamTile tamanho de cada tile em pixels.
     * @param roboto instância de fonte utilizada.
     * @param aberto estado inicial do menu (aberto/fechadi)
     */
    Menu (sf::RenderWindow* w, int tamTile, sf::Font roboto, bool aberto);

    /**
     * Trata a entrada do jogador.
     * @param input valor da entrada do jogador.
     * @return se foi possível tratar a entrada do jogador.
     */
    virtual bool trataInput (int input);

    /**
     * Fecha o menu.
     */
    void fechar (void);

    /**
     * Indica se o Menu está aberto (sendo exibido) ou não.
     * @return estado aberto/fechado.
     */
    bool estaAberto (void);

    /**
     * Getter para coordenada.
     * @return coordAtual[1]
     */
    int getCoord0 (void);

    /**
     * Getter para coordenada.
     * @return coordAtual[0]
     */
    int getCoord1 (void);

    /**
     * Reinicia estado do menu.
     */
    void reseta (void);

    /**
     * Configura a propriedade aberto para true.
     */
    void abrir (void);

    /**
     * Desenha o menu na tela.
     */
    virtual void desenha (void) {};
};

/**
 * Classe para Menu antes de começar o jogo.
 */
class MenuInicial : public Menu
{
  public:
    MenuInicial ();

    /**
     * Construtor de MenuInicial.
     * @param w ponteiro para instância de janela de SFML.
     * @param tamTile tamanho dos tiles a serem desenhados pelo menu
     * @param roboto instância da fonte utilizada pelo Menu
     * @param aberto indica o estado inicial aberto/fechado deste menu
     */
    MenuInicial(sf::RenderWindow* w, int tamTile, sf::Font roboto, bool aberto) : Menu(w, tamTile, roboto, aberto){};

    /**
     * Desenha este menu na tela.
     */
    void desenha (void) override;
};

/**
 * Classe para menu de jogo pausado.
 */
class MenuPause : public Menu
{
  public:
    MenuPause ();

    /**
     * Construtor de MenuPause.
     * @param w ponteiro para instância de janela de SFML.
     * @param tamTile tamanho dos tiles a serem desenhados pelo menu
     * @param roboto instância da fonte utilizada pelo Menu
     * @param aberto indica o estado inicial aberto/fechado deste menu
     */
    MenuPause(sf::RenderWindow* w, int tamTile, sf::Font roboto, bool aberto) : Menu(w, tamTile, roboto, aberto){};

    /**
     * Desenha este menu na tela.
     */
    void desenha (void) override;
};

/**
 * Classe para menu de batalha com uma entidade.
 */
class MenuCombate : public Menu
{
  public:
    MenuCombate ();

    /**
     * Construtor de MenuCombate.
     * @param w ponteiro para instância de janela de SFML.
     * @param tamTile tamanho dos tiles a serem desenhados pelo menu
     * @param roboto instância da fonte utilizada pelo Menu
     * @param aberto indica o estado inicial aberto/fechado deste menu
     */
    MenuCombate(sf::RenderWindow* w, int tamTile, sf::Font roboto, bool aberto) : Menu(w, tamTile, roboto, aberto){};

    /**
     * Trata a entrada do jogador para interação com o menu.
     * @param in valor da entrada (id da tecla do teclado).
     */
    bool trataInput (int in) override;

    /**
     * Desenha este menu na tela.
     */
    void desenha (void) override;
};

/**
 * Menu para quando o jogador morre.
 */
class MenuJogadorMorto : public Menu
{
  public:
    MenuJogadorMorto();

    /**
     * Construtor de MenuJogadorMorto.
     * @param w ponteiro para instância de janela de SFML.
     * @param tamTile tamanho dos tiles a serem desenhados pelo menu
     * @param roboto instância da fonte utilizada pelo Menu
     * @param aberto indica o estado inicial aberto/fechado deste menu
     */
    MenuJogadorMorto(sf::RenderWindow* w, int tamTile, sf::Font roboto, bool aberto) : Menu(w, tamTile, roboto, aberto){};

    /**
     * Desenha este menu na tela.
     */
    void desenha (void) override;
};

/**
 * Menu para quando o jogador vence o jogo
 */
class MenuFimJogo : public Menu
{
  public:
    MenuFimJogo();

    /**
     * Construtor de MenuFimJogo.
     * @param w ponteiro para instância de janela de SFML.
     * @param tamTile tamanho dos tiles a serem desenhados pelo menu
     * @param roboto instância da fonte utilizada pelo Menu
     * @param aberto indica o estado inicial aberto/fechado deste menu
     */
    MenuFimJogo(sf::RenderWindow* w, int tamTile, sf::Font roboto, bool aberto) : Menu(w, tamTile, roboto, aberto){};

    /**
     * Desenha este menu na tela.
     */
    void desenha (void) override;
};

#endif
