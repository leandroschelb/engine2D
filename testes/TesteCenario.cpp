#include <doctest/doctest.h>
#include "../src/include/Cenario.hpp"
#include "../src/include/Tilemap.hpp"

TEST_CASE("Cenário")
{
  Tilemap tilemap = Tilemap(24, 32, 20);
  tilemap.open("data/tilemapData");
  Cenario cenario = Cenario(tilemap);

  CHECK_FALSE(cenario.estaAtivo());
  cenario.setAtivo(true);
  CHECK(cenario.estaAtivo());
}
