#include <doctest/doctest.h>
#include "../src/classes/desenhavel/animado/inimigo/inimigo.hpp"

TEST_CASE("Testando inimigo")
{
  Inimigo inimigo1 = Inimigo(0, 0, 0);
  Inimigo inimigo2 = Inimigo(0, 1, 1);

  CHECK(inimigo1.getID() == 0);
  CHECK(inimigo2.getID() == 1);

  bool critico, erro;

  int variacaoVidaInimigo1 = inimigo2.ataca(inimigo1, &critico, &erro);
  CHECK(inimigo1.getVida() == 10 - variacaoVidaInimigo1);

  int variacaoVidaInimigo2 = inimigo1.ataca(inimigo2, &critico, &erro);
  CHECK(inimigo2.getVida() == 10 - variacaoVidaInimigo2);
}
