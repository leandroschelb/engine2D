#include <string>
#include <vector>
#include "animado.hpp"

Animado::Animado(std::string nome, int vida, int maxVida, int defesa, int forca, int x, int y, int altura, int largura, bool colisivo, float multiplicadorCritico, int chanceCritico, int chanceAcerto, int red, int green, int blue)
	: Desenhavel(x, y, altura, largura, colisivo, red, green, blue)
{
	this->nome = nome;
	this->vida = vida;
	this->maxVida = maxVida;
	this->defesa = defesa;
	this->forca = forca;
	this->multiplicadorCritico = multiplicadorCritico;
	this->chanceCritico = chanceCritico;
	this->chanceAcerto = chanceAcerto;
}

/**
 * Corrige a vida do jogador ao modificar propriedades de vida
 */
void Animado::corrigirVida(void)
{
  if(this->vida > this->maxVida + this->variacaoMaxVida)
  {
    this->vida = this->maxVida + this->variacaoMaxVida;
  }
  else if(this->vida < 0)
  {
    this->vida = 0;
  }
}

int Animado::getVida(void)
{
  return this->vida;
}

void Animado::variarVida(int variacao)
{
  this->vida += variacao;
  this->corrigirVida();
}

int Animado::getVariacaoMaxVida(void)
{
  return this->variacaoMaxVida;
}

void Animado::setVariacaoMaxVida(int variacao)
{
  this->variacaoMaxVida = variacao;
  this->corrigirVida();
}

int Animado::getMaxVida(void)
{
  return this->maxVida;
}

void Animado::setMaxVida(int maxVida)
{
  if (maxVida < 0) return; // throw algum erro no futuro
  this->maxVida = maxVida;
  this->corrigirVida();
}

int Animado::getDefesa(void)
{
  return this->defesa;
}

void Animado::setDefesa(int defesa)
{
  this->defesa = defesa;
}

int Animado::getForca(void)
{
  return this->forca;
}

void Animado::setForca(int forca)
{
  this->forca = forca;
}

int Animado::getVariacaoDefesa(void)
{
  return this->variacaoDefesa;
}

void Animado::setVariacaoDefesa(int variacaoDefesa)
{
  this->variacaoDefesa = variacaoDefesa;
}

int Animado::getVariacaoForca(void)
{
  return this->variacaoForca;
}

void Animado::setVariacaoForca(int variacaoForca)
{
  this->variacaoForca = variacaoForca;
}

int Animado::getTotalMaxVida (void)
{
	return this->maxVida + this->variacaoMaxVida;
}

int Animado::getTotalForca (void)
{
	int total = this->forca + this->variacaoForca;
	return total > 0 ? total : 0;
}

int Animado::getTotalDefesa (void)
{
	int total = this->defesa + this->variacaoDefesa;
	return total > 0 ? total : 0;
}
/*
std::vector<Item*> Animado::getInventario(void)
{
  return this->inventario;
}
*/
void Animado::cura (void)
{
	this->variarVida(4);
}

float Animado::getMultiplicadorCritico (void)
{
	return this->multiplicadorCritico;
}

int Animado::getChanceCritico (void)
{
	return this->chanceCritico;
}

int Animado::getChanceAcerto (void)
{
	return this->chanceAcerto;
}

bool Animado::colisaoComEntidade (Animado& entidade)
{
	return this->posicaoX >= entidade.getX() - 1 && this->posicaoX <= entidade.getX() + 1 && this->posicaoY  >= entidade.getY() - 1 && this->posicaoY  <= entidade.getY() + 1 ;
}

int Animado::ataca(Animado& entidade, bool* critico, bool* erro)
{
	int dano = 0;
    if( 1 + (std::rand() % 100) <= this->getChanceAcerto())
    {
      *erro  = false;
      if( 1 + (std::rand() % 100) <= this->getChanceCritico())
      {
		entidade.variarVida(-this->getForca() * this->getMultiplicadorCritico());
        *critico  = true;
        return this->getForca() * this->getMultiplicadorCritico();
      }

      else
      {
        *critico  = false;
        entidade.variarVida(-this->getForca());
        return this->getForca();
      }
    }
    else
    {
      *critico  = false;
      *erro  = true;
      return 0;
    }
}
