#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../include/tilemap.hpp"

tileMap::tileMap(int a, int l, int t)
{
	altura = a;
	largura = l;
	tamanhoTile = t; 
}

int tileMap::valor(int x, int y)
{
	return dados[x][y];
}

std::string tileMap::msgErro()
{
	return msgErro;
}

int tileMap::erro()
{
	return this->flagErro;
}

void tileMap::openTileMap(std::string nomeArquivo)
{
	std::ifstream arquivo(nomeArquivo);
	int aux;
	if(arquivo.is_open() == false)									// se o arquivo nao pode ser aberto, retorne vector vazio
	{
		   flagErro = true;
		   msgErro = "Arquivo nao pode ser aberto\n";
	}
	while(arquivo.is_open())										// enquanto o arquivo estiver aberto
	{
	for(int i=0; i < altura; i++)
		{
		std::vector<int> linha;									// linha a ser lida e inserida em tiles
		for(int j = 0; j < largura; j++)
		{
			if(arquivo >> aux)							// TODO: precisa verificar se as dimensões foram lidas certo
				linha.push_back(aux);
		}
		dados.push_back(linha);									// insere linha no vector
		}
	arquivo.close();												// se leu a quantidade esperada, feche arquivo
	}
}

void tileMap::imprimeTileMap()
{
	for(int i = 0; i < dados.size(); i++)
	{
		for(int j = 0; j < dados[i].size(); j++)
		{
			std::cout << dados[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/*
	*	Esta função retorna um objeto sf::Color dependendo do index passado
	*	0 : Preto
	*	1 : cinza-claro
	*	2 : red
*/
sf::Color getColor(int index)
{
	sf::Color ans;
	if(index == 0)
		ans = sf::Color(0,0,0);

	else if(index == 1)
		ans = sf::Color(169,169,169);

	else if(index == 2)
		ans = sf::Color(255,0,0);

	else if(index == 3)
		ans = sf::Color(0,0,255);

	else if(index == 4)
		ans = sf::Color(255,255,0);

	return ans;
}
