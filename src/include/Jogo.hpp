#ifndef JOGO_HEADER
#define JOGO_HEADER

#include <SFML/Graphics.hpp>
#include "./Tilemap.hpp"
#include "./Cenario.hpp"
#include "./Menu.hpp"
#include "./Combate.hpp"
#include "../classes/desenhavel/animado/jogador/jogador.hpp"
#include "../classes/desenhavel/animado/inimigo/inimigo.hpp"
#include "../include/Inventory.hpp"
#include "../include/Item.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

/**
 * Classe responsável pelo funcionamento do jogo.
 */
class Jogo {
  private:
    sf::RenderWindow* window;
    sf::Clock clock; // relogio para timing de frames
    sf::Font roboto;
    Combate* combate;
    Jogador jogador;
    std::vector<Tilemap> tilemaps;
    std::vector<Cenario> cenarios;
    unsigned cenarioAtual = 0;
    MenuInicial* menuInicial;
    MenuPause* menuPause;
    MenuJogadorMorto* menuJogadorMorto;
    MenuFimJogo* menuFimJogo;

    Inventory* inventario;

    int inimigoId = 0;
    int tamTile;
    int numLinhas;
    int numColunas;
    std::vector<Inimigo> inimigos;
  public:

    /**
     * Construtor de Jogo.
     * @param w ponteiro para instância de janela SFML.
     */
    Jogo (sf::RenderWindow* w);

    /**
     * Salva o estado do jogo.
     */
    void salvarJogo (void);

    /**
     * Carrega o último jogo salvo.
     */
    void carregarJogo (void);

    /**
     * Configura o jogo para o estado inicial.
     */
    void novoJogo (void);

    /**
     * Trata a interação do jogador com o jogo através do teclado.
     */
    void trataInput (void);

    /**
     * Configura o jogo de acordo com resultados de turno do combate.
     */
    void turnoCombate (void);

    /**
     * Carrega os inimigos de acordo com o cenário atual.
     */
    void carregaInimigos (void);

    /**
     *
     */
    void desenhaCombate();
    void desenhaTelaMorte();
    void desenhaMenuInicio();
    void desenhaMenuPause();
    void trataMenuCombate(int input);

    /**
     * Função responsável por executar o jogo, atualizando a tela com a informação necessária,
     * @param framerate número de quadros por segundo.
     */
    void gameLoop (double framerate);

    /**
     * Move o jogador para as coordenadas indicadas, se possível.
     * @param x nova coordenada X do jogador.
     * @param y nova coordenada Y do jogador.
     * @return se foi possível fazer o movimento.
     */
    bool moveJogador (int x, int y);
};

#endif
