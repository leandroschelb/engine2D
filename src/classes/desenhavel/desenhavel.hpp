#ifndef DESENHAVEL_HPP
#define DESENHAVEL_HPP

#include <SFML/Graphics.hpp>

/**
 * Classe base para objetos desenháveis.
 */
class Desenhavel {
protected:

  int posicaoX;
  int posicaoY;
  int altura;
  int largura;
  sf::RectangleShape rectangle;
  bool colisivo;

public:
  /**
   * Construtor de Desenhável
   *
   * @param _posicaoX coordenada X inicial do objeto
   * @param _posicaoY coordenada Y inicial do objeto
   * @param _altura altura do objeto
   * @param _largura largura do objeto
   * @param _colisivo indica se este objeto colide com outros ou não
   * @param red composição vermelha da cor do objeto  (0-255)
   * @param green composição verde da cor do objeto  (0-255)
   * @param blue composição azul da cor do objeto  (0-255)
   */
  Desenhavel (int posicaoX, int posicaoY, int altura, int largura, bool colisivo, int red, int green, int blue);

  /**
   * Desenha o objeto na tela.
   * @param window referência para instância de janela do SFML
   */
  virtual void desenha (sf::RenderWindow* window);

  /**
   * Getter da propriedade colisivo.
   * @return se o objeto colide com outros.
   */
  bool getColisivo (void);

  /**
   * Getter de coordenada X  (distância da esquerda) do objeto
   * @return coordenada X.
   */
  int getX (void);

  /**
   * Configura a coordenada X  (distância da esquerda) do objeto.
   * @param x novo valor da coordenada X.
   */
  virtual void setX (int x);

  /**
   * Getter de coordenada Y  (distância do topo) do objeto.
   * @return coordenada Y.
   */
  int getY (void);

  /**
   * Configura a coordenada Y  (distância do topo) do objeto.
   * @param y novo valor da coordenada Y.
   */
  virtual void setY (int y);

  /**
   * Configura uma nova coordenada para o objeto.
   * @param x novo valor da coordenada X.
   * @param y novo valor da coordenada Y.
   */
  void setPosicao (int x, int y);

  /**
   * Getter de altura do objeto.
   * @return altura do objeto
   */
  int getAltura (void);

  /**
   * Largura do objeto.
   * @return largura do objeto.
   */
  int getLargura (void);
};

#endif
