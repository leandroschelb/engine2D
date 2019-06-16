#ifndef TILEMAP_HEADER
#define TILEMAP_HEADER

class tileMap{
	std::vector<std::vector<int>> dados;
	bool flagErro = false;
	std::string msgErro = "";
public:
	int altura;
	int largura;
	int tamanhoTile;
	void openTileMap(std::string nomeArquivo);
 	int erro();
	std::string msgErro();
	int valor(int x, int y);
	void imprimeTileMap();
	tileMap(int a, int l, int t);
};

sf::Color getColor(int index);
sf::VertexArray createTile(int tileMapWidth, int tileMapHeight, int tileSize, std::vector<std::vector<int>> tiles);


#endif
