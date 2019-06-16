#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <vector>
#include "../src/classes/desenhavel/animado/jogador/jogador.hpp"

TEST_CASE("Correção do valor de vida de Entidade Animada")
{
  Jogador jogador = Jogador(0, 0);
  jogador.setVariacaoMaxVida(10);
  jogador.variarVida(20);
  CHECK(jogador.getVida() == 20);

  jogador.setVariacaoMaxVida(0);
  CHECK(jogador.getVida() == 10);

  jogador.variarVida(-20);
  CHECK(jogador.getVida() == 0);
}

TEST_CASE("Colisão entre jogadores")
{
  std::vector<Jogador> jogadores = {Jogador(5, 5), Jogador(5, 6), Jogador(5, 7)};
  CHECK(jogadores[0].colisaoComEntidade(jogadores[1]));
  CHECK_FALSE(jogadores[0].colisaoComEntidade(jogadores[2]));
  CHECK(jogadores[1].colisaoComEntidade(jogadores[2]));
}

TEST_CASE("Jogador ataca jogador")
{
  std::vector<Jogador> jogadores = {Jogador(0, 0), Jogador(0, 1)};
  bool critico, erro;
  int variacaoVidaJogador2 = jogadores[0].ataca(jogadores[1], &critico, &erro);
  int variacaoVidaJogador1 = jogadores[1].ataca(jogadores[0], &critico, &erro);
  CHECK(jogadores[0].getVida() == 10 - variacaoVidaJogador1);
  CHECK(jogadores[1].getVida() == 10 - variacaoVidaJogador2);
}

TEST_CASE("")
{
  Jogador jogador = Jogador(0, 0);
  jogador.variarVida(-5);
  jogador.cura();
  CHECK(jogador.getVida() == 9);
}

TEST_CASE("Getters e Setters")
{
  Jogador jogador = Jogador(0, 0);

  jogador.setVariacaoMaxVida(10);
  CHECK(jogador.getVariacaoMaxVida() == 10);

  jogador.setMaxVida(100);
  CHECK(jogador.getMaxVida() == 100);
  CHECK(jogador.getTotalMaxVida() == 110);

  jogador.setMaxVida(-10);
  CHECK(jogador.getMaxVida() == 100);

  CHECK(jogador.getDefesa() == 10);
  jogador.setDefesa(5);
  CHECK(jogador.getDefesa() == 5);

  CHECK(jogador.getForca() == 1);
  jogador.setForca(2);
  CHECK(jogador.getForca() == 2);

  CHECK(jogador.getVariacaoForca() == 0);
  jogador.setVariacaoForca(2);
  CHECK(jogador.getVariacaoForca() == 2);
  CHECK(jogador.getTotalForca() == 4);

  CHECK(jogador.getVariacaoDefesa() == 0);
  jogador.setVariacaoDefesa(10);
  CHECK(jogador.getVariacaoDefesa() == 10);
  CHECK(jogador.getTotalDefesa() == 15);

  CHECK(jogador.getMultiplicadorCritico() == 4.0);
  CHECK(jogador.getChanceAcerto() == 100);
  CHECK(jogador.getChanceCritico() == 20);
}
