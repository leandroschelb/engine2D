#ifndef INVENTORY_H
#define INVENTORY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Item.hpp"

class Inventory
{
  float x;
  float y;
  int slotAtual = 0;
  bool open;
  bool check_selected_slot;
  int i_slot;
  sf::RectangleShape rectangle;
  sf::RectangleShape equips[5];
  sf::Text equipName[5];
  sf::RectangleShape slots[9];
  sf::Font equipFont;
  std::vector<Item> itens;

  void swapSlotItens(int, int); //troca um item com outro nos slots
  void equipItem(int, int); //equipa um item em algum dos equips, coloca o item previamente equipado(se tiver) no slot

  public:
    /**
     * Construtor de Inventory
     */
    Inventory(float, float); //inicializa o conteudo do inventario(nao mexe na posicao de nada)

    /**
     * Configura o estado de aberto do inventário
     * @param b novo estado
     */
    void setOpen(bool); //seta o estado do inventario

    /**
     * Getter para propriedade open.
     */
    bool getOpen(); //pega o estado do inventario

    /**
     * Trata o evento de clique no item
     * @param event evento de SFML.
     * @param
     */
    void clickEvent(sf::Event&); //lida com os eventos de clique(do mouse) no inventario

    /**
     * Posiciona o inventário na tela.
     */
    void position(float, float); //posiciona todo o inventario

    /**
     * Desenha o inventário na tela.
     */
    void draw(sf::RenderWindow&); //desenha o inventario na tela

    /**
     * Insere um item no inventário.
     */
    void insertItem(Item, int);
    bool mouseContido(int, int, int, int);
};


#endif
