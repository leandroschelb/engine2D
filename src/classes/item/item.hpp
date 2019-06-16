#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

// mudar para os tipos corretos conforme forem definidos

class Item {
	private:
		std::string nome;
		std::string descricao;
		void* textura; // não sei o tipo ainda
		void* tipo;
	public:
		Item (std::string, std::string);
		std::string getNome (void);
		std::string getDescricao (void);
		void* getTipo (void);
		void onEquipar (void);
};

#endif
