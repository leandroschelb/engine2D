#ifndef ITEM_INCLUDE_HPP
#define ITEM_INCLUDE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// mudar para os tipos corretos conforme forem definidos

class Item {
	unsigned int tamanho;
	unsigned int slotAtual;
	std::string nome;
	std::string tipo;
	char simbolo;
	sf::Font roboto;
	sf::RenderWindow* window;

	public:
		Item () {};
		Item (std::string, std::string, char, sf::RenderWindow*, sf::Font);
		std::string getNome ();
		std::string getDescricao ();
		std::string getTipo ();
    unsigned int getSlotAtual();
    void setSlotAtual(int);
		void desenha(float, float);
};

#endif
