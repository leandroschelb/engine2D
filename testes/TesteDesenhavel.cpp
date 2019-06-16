#include <doctest/doctest.h>
#include "../src/classes/desenhavel/desenhavel.hpp"

TEST_CASE("Desenhavel")
{
  Desenhavel desenhavel = Desenhavel(0, 0, 10, 10, true, 0, 0, 0);

  CHECK(desenhavel.getX() == 0);
  CHECK(desenhavel.getY() == 0);

  CHECK(desenhavel.getAltura() == 10);
  CHECK(desenhavel.getLargura() == 10);

  desenhavel.setX(5);
  CHECK(desenhavel.getX() == 5);

  desenhavel.setY(20);
  CHECK(desenhavel.getY() == 20);

  desenhavel.setPosicao(10, 10);
  CHECK(desenhavel.getX() == 10);
  CHECK(desenhavel.getY() == 10);

  CHECK(desenhavel.getColisivo());
}
