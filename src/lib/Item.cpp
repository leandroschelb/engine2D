#include <string>
#include "../include/Item.hpp"

Item::Item (std::string _nome, std::string _tipo, char _simbolo, sf::RenderWindow* w, sf::Font roboto)
{
		this->nome = nome;
		this->tipo = tipo;
		this->tamanho = 20;
		this->window = w;
		this->roboto = roboto;
		this->simbolo =_simbolo;
 }

std::string Item::getNome ()
{
	return this->nome;
}

std::string Item::getTipo ()
{
	return this->tipo;
}

unsigned int Item::getSlotAtual()
{
  return this->slotAtual;
}

void Item::setSlotAtual(int i)
{
  this->slotAtual = i;
}

void Item::desenha (float px, float py)
{
	sf::RectangleShape rect(sf::Vector2f(this->tamanho, this->tamanho));
  rect.setFillColor(sf::Color::White);
	rect.setPosition(px, py);
	this->window->draw(rect);
	sf::Text aux(this->simbolo, this->roboto, this->tamanho);
	aux.setPosition(px, py);
  aux.setFillColor(sf::Color::Green);
	this->window->draw(aux);
}