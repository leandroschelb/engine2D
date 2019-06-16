#include "../animado.hpp"
#include "jogador.hpp"

Jogador::Jogador (int x, int y)
	: Animado("Jogador", 10, 10, 10, 1, x, y, 20, 20, true, 4.0, 20, 100, 0, 0, 255) {}
