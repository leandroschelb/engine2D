#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "../animado.hpp"

class Jogador : public Animado
{
	public:
		Jogador () : Jogador(6, 6) {};
		
		/**
		 * Construtor de jogador.
		 * @param x coordenada X inicial do jogador.
		 * @param y coordenada Y inicial do jogador.
		 */
		Jogador (int, int);
};

#endif
