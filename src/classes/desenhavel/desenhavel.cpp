#include "desenhavel.hpp"
#include <iostream>

Desenhavel::Desenhavel (int _posicaoX, int _posicaoY, int _altura, int _largura, bool _colisivo, int red, int green, int blue)
  : posicaoX(_posicaoX), posicaoY(_posicaoY), altura(_altura), largura(_largura), colisivo(_colisivo)
{
	this->rectangle = sf::RectangleShape(sf::Vector2f(_largura, _altura));
  this->rectangle.setFillColor(sf::Color(red, green, blue));
}

bool Desenhavel::getColisivo (void)
{
  return this->colisivo;
}

void Desenhavel::desenha (sf::RenderWindow* window)
{
	this->rectangle.setPosition(this->posicaoX * this->largura, this->posicaoY * this->altura);
	window->draw(this->rectangle);
}

int Desenhavel::getX (void)
{
  return this->posicaoX;
}

void Desenhavel::setX (int x)
{
  this->posicaoX = x;
}

int Desenhavel::getY (void)
{
  return this->posicaoY;
}

void Desenhavel::setY (int y)
{
  this->posicaoY = y;
}

void Desenhavel::setPosicao (int x, int y)
{
  this->posicaoX = x;
  this->posicaoY = y;
}

int Desenhavel::getAltura (void)
{
  return this->altura;
}

int Desenhavel::getLargura (void)
{
  return this->largura;
}
