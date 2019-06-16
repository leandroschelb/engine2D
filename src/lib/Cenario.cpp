#include <SFML/Graphics.hpp>
#include "../include/Tilemap.hpp"
#include "../include/Cenario.hpp"
#include <iostream>

Cenario::Cenario (Tilemap tilemap)
{
	this->ativo = false;
	this->tiles.setPrimitiveType(sf::Quads);
	this->tiles.resize(tilemap.largura * tilemap.altura * 4);

	// populate the vertex array, wyth one quad per tyle
	for (unsigned int y = 0; y < tilemap.altura; ++y)
		for (unsigned int x = 0; x < tilemap.largura; ++x)
		{
			// get the current tyle number
			//int tyleNumber = tyles[y + x * wydth];
			int qualTile = (y*tilemap.largura) + x;

			sf::Vertex* quad = &this->tiles[(qualTile) * 4];

			quad[0].position = sf::Vector2f(x * tilemap.tamanhoTile, y * tilemap.tamanhoTile);
			quad[1].position = sf::Vector2f((x + 1) * tilemap.tamanhoTile, y * tilemap.tamanhoTile);
			quad[2].position = sf::Vector2f((x + 1) * tilemap.tamanhoTile, (y + 1) * tilemap.tamanhoTile);
			quad[3].position = sf::Vector2f(x * tilemap.tamanhoTile, (y + 1) * tilemap.tamanhoTile);

			quad[0].color = quad[1].color = quad[2].color = quad[3].color = getColor(tilemap.valor(x, y));
		}
}

bool Cenario::estaAtivo (void)
{
  return this->ativo;
}

void Cenario::setAtivo (bool b)
{
	this->ativo = b;
}
