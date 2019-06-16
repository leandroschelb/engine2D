#ifndef COMBATE_HEADER
#define COMBATE_HEADER

#include <SFML/Graphics.hpp>
#include "./Menu.hpp"
#include "../classes/desenhavel/animado/jogador/jogador.hpp"
#include "../classes/desenhavel/animado/inimigo/inimigo.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

/**
 * Classe responsável pelo controle de combate entre duas entidades (Jogador e Inimigo).
 */
class Combate
{
  public:
    int turnoNumero = 0;
    int tamTile;
    int coordAtual[2];
    bool ativo;
    Jogador* jogador;
    Inimigo* inimigo;
    MenuCombate* menu;
    sf::RenderWindow* window;
    sf::Font roboto;

    /**
     * Construtor de combate (tela de combate)
     * @param w instância de janela do SFML
     * @param tamTile tamanho de cada tile
     * @param roboto fonte utilizada
     */
    Combate (sf::RenderWindow* w, int tamTile, sf::Font roboto);
    ~Combate (void);

    /**
     * Trata a entrada do usuário para interagir com a tela.
     * @return se a tecla pressionada foi tratada ou não.
     */
    bool input (int in);

    /**
     * Simula um turno de combate entre as entidades.
     * @return -1 se jogador morre, 0 se nada muda e 1 se inimigo morre.
     */
    int turno (void);

    /**
     * Desenha a tela de combate na tela SFML.
     */
    void desenha (void);

    /**
     * Ativa a tela de combate.
     * @param j jogador jogador do combate
     * @param i inimigo inimigo do combate
     */
    void ativar(Jogador* j, Inimigo* i);

    /**
     * Verifica se a tela de combate é a tela exibida no jogo.
     * @return ativo.
     */
    bool estaAtivo(void);
};

#endif
