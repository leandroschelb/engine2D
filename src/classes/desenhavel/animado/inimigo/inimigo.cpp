#include "../animado.hpp"
#include "inimigo.hpp"

Inimigo::Inimigo (int x, int y, int _id)
	: Animado("Inimigo", 10, 10, 10, 1, x, y, 20, 20, true, 4.0, 8, 20, 255, 0, 0), id(_id) {}

int Inimigo::getID (void)
{
	return this->id;
}
