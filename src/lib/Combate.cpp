#include "../include/Combate.hpp"

Combate::Combate(sf::RenderWindow* w, int tamTile, sf::Font roboto)
{
  this->ativo = false;
  this->menu = new MenuCombate(w, tamTile, roboto, true);
  this->window = w;
  this->tamTile = tamTile;
  this->roboto = roboto;
};

bool Combate::input (int in)
{
  return this->menu->trataInput(in);
}

int Combate::turno (void)
{
  bool* flagCritico = new bool(true);
  bool* flagErro = new bool(true);
  this->turnoNumero++;
  std::cout << "\n------------  "<< this->turnoNumero <<"  -------------\n";
  std::cout << "Jogador ataca: " << this->jogador->ataca(*inimigo, flagCritico, flagErro) << " de dano\n";
  std::cout << "Inimigo causa: " << this->inimigo->ataca(*(this->jogador), flagCritico, flagErro) << " de dano\n";

  if(this->jogador->getVida() <= 0)
  {
    std::cout << "Voce morreu!\n";
    this->ativo = false;
    return -1;
  }

  else if(this->inimigo->getVida() <= 0)
  {
    std::cout << "Jogador derrotou o inimigo!\n";
    this->ativo = false;
    return 1;
  }
  return 0;
}

void Combate::desenha (void)
{
  sf::RectangleShape background(sf::Vector2f(this->window->getSize().x, this->window->getSize().x));
  background.setFillColor(sf::Color(255, 255, 255));

  sf::RectangleShape menu(sf::Vector2f(this->window->getSize().x -40, 7*this->tamTile));
  menu.setPosition(0*this->tamTile + 20, 16*this->tamTile );
  menu.setFillColor(sf::Color(255, 255, 255));
  menu.setOutlineThickness(10);
  menu.setOutlineColor(sf::Color(200, 200, 200));

  sf::RectangleShape jogador(sf::Vector2f(6*this->tamTile, 6*this->tamTile));
  jogador.setPosition(0*this->tamTile + 60, 9*this->tamTile );
  jogador.setFillColor(sf::Color(0, 0, 255));

  sf::RectangleShape inimigo(sf::Vector2f(6*this->tamTile, 6*this->tamTile));
  inimigo.setPosition(24*this->tamTile, 2*this->tamTile );
  inimigo.setFillColor(sf::Color(255, 0, 0));

  sf::RectangleShape vidaInimigo(sf::Vector2f(this->inimigo->getVida() * this->tamTile, 1*this->tamTile));
  vidaInimigo.setPosition(3*this->tamTile, 3*this->tamTile );
  vidaInimigo.setFillColor(sf::Color(0, 255, 0));

  sf::RectangleShape vidaInimigoTotal(sf::Vector2f(10*this->tamTile, 1*this->tamTile));
  vidaInimigoTotal.setPosition(3*this->tamTile, 3*this->tamTile );
  vidaInimigoTotal.setFillColor(sf::Color(220, 220, 220));

  sf::RectangleShape vidaJogador(sf::Vector2f(this->jogador->getVida() * this->tamTile, 1*this->tamTile));
  vidaJogador.setPosition(20*this->tamTile, 12*this->tamTile );
  vidaJogador.setFillColor(sf::Color(0, 225, 0));

  sf::RectangleShape vidaJogadorTotal(sf::Vector2f(10*this->tamTile, 1*this->tamTile));
  vidaJogadorTotal.setPosition(20*this->tamTile, 12*this->tamTile );
  vidaJogadorTotal.setFillColor(sf::Color(220, 220, 220));

  sf::Text nomeInimigo("inimigo", this->roboto, 35);
  nomeInimigo.setPosition(2*this->tamTile,0);
  nomeInimigo.setFillColor(sf::Color(0,0,0));

  sf::Text nomeJogador("Jogador", this->roboto, 35);
  nomeJogador.setPosition(19*this->tamTile, 9*this->tamTile);
  nomeJogador.setFillColor(sf::Color(0,0,0));

  sf::Text hp("HP",  this->roboto, 35);
  hp.setPosition(0*this->tamTile+5, 2*this->tamTile);
  hp.setFillColor(sf::Color(0,0,0));

  sf::Text hp2 = hp;
  hp2.setPosition(17*this->tamTile+5, 11*this->tamTile);
  hp2.setFillColor(sf::Color(0,0,0));

  this->window->draw(background);
  this->window->draw(menu);
  this->window->draw(jogador);
  this->window->draw(inimigo);
  this->window->draw(vidaInimigoTotal);
  this->window->draw(vidaInimigo);
  this->window->draw(vidaJogadorTotal);
  this->window->draw(vidaJogador);
  this->window->draw(nomeInimigo);
  this->window->draw(nomeJogador);
  this->window->draw(hp);
  this->window->draw(hp2);
  this->menu->desenha();
}

bool Combate::estaAtivo (void)
{
  return this->ativo;
}

void Combate::ativar(Jogador* j, Inimigo* i)
{
  this->jogador = j;
  this->inimigo = i;
  this->ativo = true;
}
