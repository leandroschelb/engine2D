#ifndef TILEMAP_HEADER
#define TILEMAP_HEADER

#include <SFML/Graphics.hpp>

class Tile
{
	public:
		int tipo;
		bool andavel;
		Tile(int t, bool a)
		{
			this->tipo = t;
			this->andavel = a;
		};
};

/**
 * Classe responsável por ler arquivo de tilemap e conhecer cada tile.
 */
class Tilemap
{
	std::vector<std::vector<Tile>> dados;
	bool flagErro = false;
	std::string msgErro = "";
public:
	unsigned altura;
	unsigned largura;
	unsigned tamanhoTile;

  /**
   * Abre um arquivo de tilemap e configura o objeto para o arquivo aberto.
   * @param nomeArquivo nome do arquivo de tilemap a ser aberto.
   */
  void open(std::string nomeArquivo);

  /**
   * Valor de tile na posição (x, y)
   * @param x coordenada X desejada
   * @param y coordenada Y desejada
   * @return valor do tile na coordenada (x, y)
   */
	int valor(int x, int y);

  /**
   * Indica se é possível andar sobre o tile na posição (x, y)
   * @param x coordenada X desejada.
   * @param y coordenada Y desejada.
   * @return se o tile em (x, y) é "andável"
   */
	bool andavel(int x, int y);

  /**
   * Imprime no console o tilemap lido.
   */
	void imprime();

  Tilemap() {};

  /**
   * Construtor de Tilemap
   * @param a altura (número de linhas) do tilemap
   * @param l largura (número de colunas) do tilemap
   * @param t tamanho do tile do tilemap
   */
	Tilemap(int a, int l, int t);
};

/**
 * Retorna a cor de um tipo de tile.
 * @param tipoTile tipo de tile.
 */
sf::Color getColor(int tipoTile);


#endif
