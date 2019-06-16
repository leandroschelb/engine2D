#ifndef ESPADA_HPP
#define ESPADA_HPP

#include <string>
#include "../item.hpp"

class Espada : public Item {
	private:
		int forca;
		int velocidade;
	public:
		Espada (void);
		int getForca (void);
		int getVelocidade (void);
};

#endif
