#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../include/Tilemap.hpp"

Tilemap::Tilemap(int a, int l, int t)
{
		this->altura = a;
		this->largura = l;
		this->tamanhoTile = t;
}

int Tilemap::valor(int x, int y)
{
	if(y < 0 || y >= this->dados.size())
		return - 1;
	if(x < 0 || x >= this->dados[0].size())
		return - 1;
	return this->dados[y][x].tipo;
}

bool Tilemap::andavel(int x, int y)
{
	if(y < 0 || y >= this->dados.size())
		return false;
	if(x < 0 || x >= this->dados[0].size())
		return false;
	return this->dados[y][x].andavel;
}

void Tilemap::open(std::string nomeArquivo)
{
	std::ifstream arquivo(nomeArquivo);
	int aux;
	if(arquivo.is_open() == false)									// se o arquivo nao pode ser aberto, retorne vector vazio
	{
		   throw 1;
	}
	while(arquivo.is_open())										// enquanto o arquivo estiver aberto
	{
	for(unsigned int i=0; i < altura; i++)
		{
		std::vector<Tile> linha;									// linha a ser lida e inserida em tiles
		for(unsigned int j = 0; j < largura; j++)
		{
			if(arquivo >> aux)							// TODO: precisa verificar se as dimensões foram lidas certo
			{
				linha.push_back(Tile(aux, (aux == 7 || aux == 2 || aux == 0) ? true : false  ));
			}
		}
		dados.push_back(linha);									// insere linha no vector
		}
	arquivo.close();												// se leu a quantidade esperada, feche arquivo
	}
}

void Tilemap::imprime()
{
	for(unsigned int i = 0; i < dados.size(); i++)
	{
		for(unsigned int j = 0; j < dados[i].size(); j++)
		{
			std::cout << dados[i][j].tipo << " ";
		}
		std::cout << std::endl;
	}
}

sf::Color getColor(int tipoTile)
{
  switch(tipoTile)
  {
    case 0:
      return sf::Color(37, 209, 33);
    case 1:
      return sf::Color(25, 252, 210);
    case 2:
      return sf::Color(169, 169, 169);
    case 3:
      return sf::Color(169,169,169);
    case 4:
      return sf::Color(255,215,0);
    case 6:
			return sf::Color(239, 75, 56);
    case 7:
      return sf::Color(27,17,23);
    default:
      return sf::Color(239, 75, 56);
  }
}
