#include "inanimado.hpp"

Inanimado::Inanimado (int x, int y, int altura, int largura, bool colisivo, int _dano)
	: Desenhavel(x, y, altura, largura, textura, colisivo), dano(_dano) {}

int Inanimado::getDano (void)
{
	return this->dano;
}

void Inanimado::desenhar (void)
{
	// desenhar a si mesmo, TODO
}
