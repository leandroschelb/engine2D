#ifndef INANIMADO_HPP
#define INANIMADO_HPP

#include "../desenhavel.hpp"

/**
 * Classe para entidades desenháveis não vivas.
 */
class Inanimado : public Desenhavel {
	private:
		int dano; // dano que este item causa ao jogador quando há colisão
	public:
    /**
     * Construtor de inanimado (entidade sem vida)
     * @param x coordenada X inicial da entidade.
     * @param y coordenada Y inicial da entidade.
     * @param altura altura da entidade.
     * @param largura largura da entidade.
     * @param colisivo se a entidade colide com objetos ou nãonce
     * @param _dano dano causado pela entidade a outra entidade (por exemplo, se a entidade por um cacto causa dano ao colidir)
     */
		Inanimado (int, int, int, int, bool, int);

    /**
     * Getter do dano causado por esta entidade.
     * @return dano.
     */
		int getDano (void);

    /**
     * Desenha a si mesmo na janela.
     * @param window referência para janela de SFML.
     */
		void desenhar (void);
};

#endif
