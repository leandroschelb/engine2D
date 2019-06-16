#include <doctest/doctest.h>
#include "../src/include/Tilemap.hpp"

TEST_CASE("Classe Tilemap")
{
  Tilemap tilemap = Tilemap(24, 32, 20);
  tilemap.open("data/tilemapData");

  CHECK(tilemap.altura == 24);
  CHECK(tilemap.largura == 32);
  CHECK(tilemap.tamanhoTile == 20);

  CHECK(tilemap.valor(0, 0) == 3);
  CHECK(tilemap.valor(-1, 1) == -1);
  CHECK(tilemap.valor(1, -1) == -1);
  CHECK(tilemap.valor(32, 32) == -1);

  CHECK_FALSE(tilemap.andavel(0, 0));
  CHECK_FALSE(tilemap.andavel(-1, 1));
  CHECK_FALSE(tilemap.andavel(1, -1));
  CHECK(tilemap.andavel(1, 1));

  CHECK(getColor(0) == sf::Color(37, 209, 33));
  CHECK(getColor(1) == sf::Color(25, 252, 210));
  CHECK(getColor(2) == sf::Color(169, 169, 169));
  CHECK(getColor(3) == sf::Color(169, 169, 169));
  CHECK(getColor(4) == sf::Color(255, 215, 0));
  CHECK(getColor(5) == sf::Color(239, 75, 56));
  CHECK(getColor(6) == sf::Color(239, 75, 56));
  CHECK(getColor(7) == sf::Color(27, 17, 23));
}
