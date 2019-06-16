#include <string>
#include "../item.hpp"
#include "espada.hpp"

Espada::Espada (void) : Item("Espada", "Uma espada"), forca(10), velocidade(1) {}

int Espada::getForca (void)
{
	return this->forca;
}

int Espada::velocidade (void)
{
	return this->velocidade;
}
