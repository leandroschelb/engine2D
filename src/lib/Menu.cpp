#include "../include/Menu.hpp"

Menu::Menu(sf::RenderWindow* w, int tamTile, sf::Font roboto, bool aberto)
{
  this->numOpcoes = 2;
  this->window = w;
  this->tamTile = tamTile;
  this->roboto = roboto;
  this->aberto = aberto;
  this->coordAtual[0] = 0;
  this->coordAtual[1] = 0;
}

bool Menu::trataInput (int input)
{
  if(this->aberto == false)
    return false;
  switch(input)
  {
    case sf::Keyboard::W:
      this->coordAtual[0] = this->coordAtual[0]  - 1  <  0? this->numOpcoes - 1 : this->coordAtual[0] - 1;
      return true;
      break;
    case sf::Keyboard::S:
      this->coordAtual[0] = this->coordAtual[0]  + 1  >=  this->numOpcoes ? 0 : this->coordAtual[0] + 1;
      return true;
      break;
  }
  return false;
}

void Menu::fechar (void)
{
  this->aberto = false;
}

bool Menu::estaAberto (void)
{
  return this->aberto;
}

int Menu::getCoord1 (void)
{
  return this->coordAtual[1];
}

int Menu::getCoord0 (void)
{
  return this->coordAtual[0];
}

void Menu::reseta (void)
{
  this->coordAtual[0] = 0;
  this->coordAtual[1] = 0;
}

void Menu::abrir (void)
{
  this->aberto = true;
}

void MenuInicial::desenha (void)
{
  sf::RectangleShape background (sf::Vector2f(this->window->getSize().x, this->window->getSize().x));
  background.setFillColor(sf::Color(255,255,255));

  sf::Text titulo("The legend of Jeremias", this->roboto, 48);
  titulo.setPosition(3*this->tamTile, 3*this->tamTile);
  titulo.setFillColor(sf::Color(0,0,255));

  sf::Text novoJogo("Novo Jogo", this->roboto, 24);
  novoJogo.setPosition(13*this->tamTile, 8*this->tamTile);
  novoJogo.setFillColor(sf::Color::Black);

  sf::Text carregarJogo("Carregar jogo", this->roboto, 24);
  carregarJogo.setPosition(13*this->tamTile, 10*this->tamTile);
  carregarJogo.setFillColor(sf::Color::Black);

  sf::Text seta("->", this->roboto, 24);
  seta.setFillColor(sf::Color::Black);
  if(this->coordAtual[0] == 0)
  {
    seta.setPosition(11*this->tamTile, 8*this->tamTile);
  }
  else
  {
    seta.setPosition(11*this->tamTile, 10*this->tamTile);
  }

  this->window->draw(background);
  this->window->draw(titulo);
  this->window->draw(novoJogo);
  this->window->draw(carregarJogo);
  this->window->draw(seta);
}

void MenuPause::desenha (void)
{
  sf::RectangleShape fundoFiltro (sf::Vector2f(this->window->getSize().x, this->window->getSize().x));
  fundoFiltro.setFillColor(sf::Color(0,0,0,200));

  sf::RectangleShape menu(sf::Vector2f(10*this->tamTile, 11*this->tamTile));
  menu.setPosition(11*this->tamTile, 2*this->tamTile);
  menu.setFillColor(sf::Color(180,180,180));
  menu.setOutlineThickness(10);
  menu.setOutlineColor(sf::Color(200, 200, 200));

  sf::Text strSalvar("Salvar", this->roboto, 24);
  strSalvar.setPosition(13*this->tamTile, 3*this->tamTile);
  if(this->coordAtual[0] == 0)
    strSalvar.setFillColor(sf::Color::Red);
  else
    strSalvar.setFillColor(sf::Color::Black);

  sf::Text strSair("Sair", this->roboto, 24);
  strSair.setPosition(13*this->tamTile, 6*this->tamTile);

  if(this->coordAtual[0] == 1)
    strSair.setFillColor(sf::Color::Red);
  else
    strSair.setFillColor(sf::Color::Black);


  this->window->draw(fundoFiltro);
  this->window->draw(menu);
  this->window->draw(strSalvar);
  this->window->draw(strSair);
}

bool MenuCombate::trataInput (int in)
{
  if(this->coordAtual[1] == 1)
  {
    if(in == sf::Keyboard::A)
    {
      this->coordAtual[0] = this->coordAtual[0] - 1 < 0 ? 0 :  this->coordAtual[0] -1;
      return true;
    }
    if(in == sf::Keyboard::D)
    {
      this->coordAtual[0] = this->coordAtual[0] + 1 > 1 ? 1 :  this->coordAtual[0] + 1;
      return true;
    }
  }

  if(in == sf::Keyboard::Enter)
  {
    if(this->coordAtual[1] == 0)
    {
      this->coordAtual[1] = 1;
      return true;
    }
    else
    {
      return false;
    }
  }
return true;
}

void MenuCombate::desenha (void)
{
  if(this->getCoord1() == 0)
  {
  sf::Text strAtaque("Habilidades", this->roboto, 35);
  strAtaque.setPosition(4*this->tamTile,17*this->tamTile);
  strAtaque.setFillColor(sf::Color::Black);

  sf::Text strItems("Items", this->roboto, 35);
  strItems.setPosition(19*this->tamTile,17*this->tamTile);
  strItems.setFillColor(sf::Color::Black);

  sf::Text seta("->", this->roboto, 24);
  seta.setFillColor(sf::Color::Black);
  if(this->getCoord0() == 0)
  {
      seta.setPosition(3*this->tamTile, 17*this->tamTile);
  }
  else
  {
      seta.setPosition(18*this->tamTile, 17*this->tamTile);
  }

  //this->window->draw(strItems);
  this->window->draw(strAtaque);
  this->window->draw(seta);
  }
  else if(this->getCoord1() == 1)
  {
  sf::Text skill1("Ataque normal", this->roboto, 35);
  skill1.setPosition(4*this->tamTile,17*this->tamTile);
  skill1.setFillColor(sf::Color::Black);

  sf::Text skill2("Cura", this->roboto, 35);
  skill2.setPosition(20*this->tamTile,17*this->tamTile);
  skill2.setFillColor(sf::Color::Black);


  sf::Text seta("->", this->roboto, 24);
  seta.setFillColor(sf::Color::Black);
  if(this->getCoord0() == 0)
  {
      seta.setPosition(3*this->tamTile, 17*this->tamTile);
  }
  else
  {
      seta.setPosition(19*this->tamTile, 17*this->tamTile);
  }

  this->window->draw(skill1);
  this->window->draw(skill2);
  this->window->draw(seta);
  }
}

void MenuJogadorMorto::desenha (void)
{
  sf::RectangleShape background(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
  background.setFillColor(sf::Color(0, 0, 0, 180));

  sf::RectangleShape fundoLetras(sf::Vector2f(this->window->getSize().x, 12*this->tamTile));
  fundoLetras.setPosition(0, 2*this->tamTile);
  fundoLetras.setFillColor(sf::Color(0, 0, 0, 255));

  sf::Text nomeInimigo("Voce morreu", this->roboto, 82);
  nomeInimigo.setPosition(4*this->tamTile,6*this->tamTile);
  nomeInimigo.setFillColor(sf::Color::Red);

  sf::Text descricao(L"aperte ENTER para voltar para tela inicial!", this->roboto, 24);
  descricao.setPosition(5*this->tamTile, 16*this->tamTile);
  descricao.setFillColor(sf::Color::Red);

  this->window->draw(background);
  this->window->draw(fundoLetras);
  this->window->draw(nomeInimigo);
  this->window->draw(descricao);
}

void MenuFimJogo::desenha (void)
{
  sf::RectangleShape rect(sf::Vector2f(this->window->getSize().x, this->window->getSize().x) );
  rect.setFillColor(sf::Color::White);
  this->window->draw(rect);

  sf::Text parabens("PARABENS", this->roboto, 82);
  parabens.setPosition(6*this->tamTile,6*this->tamTile);
  parabens.setFillColor(sf::Color::Cyan);

  sf::Text descricao(L"aperte ENTER para voltar para tela inicial!", this->roboto, 24);
  descricao.setPosition(5*this->tamTile, 16*this->tamTile);
  descricao.setFillColor(sf::Color::Cyan);

  this->window->draw(rect);
  this->window->draw(parabens);
  this->window->draw(descricao);
}
