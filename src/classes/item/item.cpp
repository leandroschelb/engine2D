#include <string>
#include "item.hpp"

Item::Item (std::string _nome, std::string _descricao)
 : nome(_nome), descricao(_descricao) {}

std::string Item::getNome (void)
{
	return this->nome;
}

std::string Item::getDescricao (void)
{
	return this->descricao;
}

void* Item::getTipo (void)
{
	return this->tipo;
}

void Item::onEquipar (void)
{
  // TODO ação ao equipar item
}
