#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "../animado.hpp"

/**
 * Classe base para inimigos.
 */
class Inimigo : public Animado
{
	private:
		int id;
	public:
		Inimigo () : Inimigo(0, 0, 1) {};

		/**
		 * Construtor de inimigo.
		 * @param x coordenada X inicial de inimigo.
		 * @param y coordenada Y inicial de inimigo.
		 * @param _id identificador do inimigo.
		 */
		Inimigo (int x, int y, int _id);

		/**
		 * Getter de identificador de inimigo.
		 * @return id do inimigo.
		 */
		int getID (void);
};

#endif
