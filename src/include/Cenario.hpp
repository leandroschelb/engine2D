#ifndef CENARIO_HEADER
#define CENARIO_HEADER

#include <SFML/Graphics.hpp>
#include "./Tilemap.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

/**
 * Classe responsável pelos cenários desenhados na tela.
 */
class Cenario
{
  private:
    bool ativo;
  public:
    sf::VertexArray tiles;
    Cenario () { };

    /**
     * Construtor de Cenário.
     * @param tilemap tilemap do cenário.
     */
    Cenario (Tilemap tilemap);

    /**
     * Verifica se este cenário está ativo.
     * @return ativo.
     */
    bool estaAtivo (void);

    /**
     * Configura propriedade ativo do cenário.
     * @param b novo valor de ativo.
     */
    void setAtivo (bool b);
};



#endif
