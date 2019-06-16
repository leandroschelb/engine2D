#include "../include/Jogo.hpp"

Jogo::Jogo (sf::RenderWindow* w)
{
  // estas variaveis são constantes e não mudam entre gameplays
  this->window = w;
  this->tamTile = 20;
  this->numColunas = this->window->getSize().x/this->tamTile;
  this->numLinhas = this->window->getSize().y/this->tamTile;
  this->tilemaps.push_back(Tilemap(this->numLinhas, this->numColunas, this->tamTile));
  this->jogador = Jogador(3, 2);
  try
  {
    this->tilemaps[0].open("data/tilemapData");
  }
  catch(int x)
  {
    if(x == 1)
    {
      std::cout << "Erro na leitura do arquivo\n";
      return ;
    }
  }

  this->tilemaps.push_back(Tilemap((this->window->getSize().y/this->tamTile),(this->window->getSize().x/this->tamTile), this->tamTile));
  try
  {
    this->tilemaps[1].open("data/tilemapData2");
  }
  catch(int x)
  {
    if(x == 1)
    {
      std::cout << "Erro na leitura do arquivo\n";
      return ;
    }
  }

  this->tilemaps.push_back(Tilemap((this->window->getSize().y/this->tamTile),(this->window->getSize().x/this->tamTile), this->tamTile));
  try
  {
    this->tilemaps[2].open("data/tilemapData3");
  }
  catch(int x)
  {
    if(x == 1)
    {
      std::cout << "Erro na leitura do arquivo\n";
      return ;
    }
  }

  for (Tilemap& tilemap : this->tilemaps)
  {
	  this->cenarios.push_back(Cenario(tilemap));
  }

  if (!this->roboto.loadFromFile("data/fonts/Roboto/Roboto-Bold.ttf"))
  {
      std::cout << "erro em carregar fonte\n";
      return;
  }
  this->clock.restart();
  this->novoJogo();
  this->menuInicial = new MenuInicial(w, this->tamTile, this->roboto, true);
  this->menuPause = new MenuPause(w, this->tamTile, this->roboto, false);
  this->menuJogadorMorto = new MenuJogadorMorto(w, this->tamTile, this->roboto, false);
  this->menuFimJogo = new MenuFimJogo(w, this->tamTile, this->roboto, false);
}

void Jogo::gameLoop (double framerate)
{
  while(this->window->isOpen())
  {
    if(this->clock.getElapsedTime().asMilliseconds() >= (1.0/framerate))
    {
      this->clock.restart();
    }
    else
    {
      sf::sleep(sf::milliseconds(2));
      continue;
    }

    this->trataInput();
    this->window->clear();
    
    if(this->menuInicial->estaAberto())
    {
      this->menuInicial->desenha();
    }
    else if(this->cenarios[this->cenarioAtual].estaAtivo() || this->menuJogadorMorto->estaAberto() || this->menuPause->estaAberto() || this->inventario->getOpen())
    {
	  this->window->draw(this->cenarios[this->cenarioAtual].tiles);
	  this->jogador.desenha(this->window);

	  for (Inimigo& inimigo : this->inimigos)
	  {
		  inimigo.desenha(this->window);
	  }

      if(this->menuPause->estaAberto())
      {
        this->menuPause->desenha();
      }

      else if(this->menuJogadorMorto->estaAberto())
      {
        this->menuJogadorMorto->desenha();
      }
    }
    else if(this->combate->estaAtivo())
    {
      this->combate->desenha();
    }
    if(this->menuInicial->estaAberto())
    {
      this->menuInicial->desenha();
    }
    if(this->menuFimJogo->estaAberto())
      this->menuFimJogo->desenha();
    
    if(this->inventario->getOpen())
      this->inventario->draw(*this->window);
    this->window->display();
  }
}

void Jogo::trataInput()
{
  sf::Event event;
  while (this->window->pollEvent(event))
  {
    switch (event.type)
    {
      case sf::Event::Closed:
          this->window->close();
          break;
      case sf::Event::KeyPressed:
        switch (event.key.code)
        {
          case sf::Keyboard::Enter:
            if(this->menuJogadorMorto->estaAberto() || this->menuFimJogo->estaAberto())
            {
              this->menuInicial->abrir();
              this->menuJogadorMorto->fechar();
              this->menuFimJogo->fechar();
              this->novoJogo();
            }
            else if(this->menuInicial->estaAberto())
            {
              switch(this->menuInicial->getCoord0())
              {
                case 0:
                  std::cout << "Iniciando jogo\n";
                  this->cenarios[this->cenarioAtual].setAtivo(true);
                  this->menuInicial->fechar();
                  break;
                case 1:
                  this->carregarJogo();
                  break;
              }
            }
            else if(this->menuPause->estaAberto())
            {
              switch(this->menuPause->getCoord0())
              {
                case 0:
                  this->salvarJogo();
                  break;
                case 1:
                  std::cout << "Fechando o jogo...\n";
                  this->window->close();
                  break;
              }
            }

            else if(this->combate->estaAtivo())
            {
              if(this->combate->input(sf::Keyboard::Enter))
              {
                if(this->combate->menu->getCoord0() == 1)
                {
                  std::cout << "Items não implementados\n";
                  this->combate->menu->reseta();
                }
              }
              else
              {
                switch(this->combate->menu->getCoord0())
                {
                  case 0:
                    this->turnoCombate();
                    break;
                  case 1:
                    this->jogador.cura();
                    break;
                }
                this->combate->menu->reseta();
              }
            }
            break;

          case sf::Keyboard::Escape:
            if(this->cenarios[this->cenarioAtual].estaAtivo())
            {
              this->cenarios[this->cenarioAtual].setAtivo(false);
              this->menuPause->abrir();
            }
            else if(this->menuPause->estaAberto())
            {
              this->cenarios[this->cenarioAtual].setAtivo(true);
              this->menuPause->fechar();
            }
            break;

          case sf::Keyboard::W:
            if(this->menuInicial->estaAberto())
              this->menuInicial->trataInput(sf::Keyboard::W);
            else if(this->menuPause->estaAberto())
              this->menuPause->trataInput(sf::Keyboard::W);
            else if(this->cenarios[this->cenarioAtual].estaAtivo())
              this->moveJogador(this->jogador.getX(), this->jogador.getY() - 1);
            break;

          case sf::Keyboard::S:
            if(this->menuInicial->estaAberto())
              this->menuInicial->trataInput(sf::Keyboard::S);
            else if(this->menuPause->estaAberto())
              this->menuPause->trataInput(sf::Keyboard::S);
            else if(this->cenarios[this->cenarioAtual].estaAtivo())
              this->moveJogador(this->jogador.getX(), this->jogador.getY() + 1);

            break;

          case sf::Keyboard::D:
            if(this->combate->estaAtivo())
              this->combate->input(sf::Keyboard::D);
            else if(this->cenarios[this->cenarioAtual].estaAtivo())
              this->moveJogador(this->jogador.getX() + 1, this->jogador.getY());
            break;

          case sf::Keyboard::A:
            if(this->combate->estaAtivo())
              this->combate->input(sf::Keyboard::A);
            else if(this->cenarios[this->cenarioAtual].estaAtivo())
              this->moveJogador(this->jogador.getX() - 1, this->jogador.getY() );
            break;

          case sf::Keyboard::E:
            if(this->cenarios[this->cenarioAtual].estaAtivo())
            { 
              this->cenarios[this->cenarioAtual].setAtivo(false);            
              this->inventario->setOpen(true);
            }
            else if(this->cenarios[this->cenarioAtual].estaAtivo() == false && this->inventario->getOpen())
            {
              this->cenarios[this->cenarioAtual].setAtivo(true);            
              this->inventario->setOpen(false);
            }
            break;

          case sf::Keyboard::Space:
            if(this->cenarios[this->cenarioAtual].estaAtivo())
            {
              for(int i = 0; i < this->inimigos.size(); i++)
              {
                if (this->jogador.colisaoComEntidade(this->inimigos[i]))
                {
                  inimigoId = i;
                  this->cenarios[cenarioAtual].setAtivo(false);
                  this->combate->ativar(&this->jogador, &this->inimigos[i]);
                  break;
                }
              }
            }
            break;

          default:
            break;
        }
        break;

      case sf::Event::MouseButtonPressed:
        switch(event.mouseButton.button)
        {
          case sf::Mouse::Left:
            if(this->inventario->getOpen())
            {
              std::cout << "potencial click\n";
              this->inventario->clickEvent(event);
            }
            break;
        }
        break;
    }
  }
}

void Jogo::carregaInimigos()
{
  if(this->cenarioAtual == 0)
  {
    this->inimigos.resize(0);
    this->inimigos.push_back(Inimigo(4, 4, 1));
    this->inimigos.push_back(Inimigo(10, 4, 2));
  }
  else if(this->cenarioAtual == 1)
  {
    this->inimigos.resize(0);
    this->inimigos.push_back(Inimigo(14, 4, 3));
  }
}

void Jogo::turnoCombate()
{
  int resultadoTurno = this->combate->turno();

  if(resultadoTurno == -1)
  {
    this->menuJogadorMorto->abrir();
  }

  else if(resultadoTurno == 1)
  {
    std::cout << "morreu: " << this->combate->inimigo->getID() << "\n";
    this->inimigos.erase( this->inimigos.begin() + inimigoId );
    this->cenarios[this->cenarioAtual].setAtivo(true);

    if(this->inimigos.size() == 0)
    {
      this->cenarioAtual++;
      this->jogador.setPosicao(14,22);
      this->carregaInimigos();
      std::cout << "Todos inimigos derrotados!\n";
      this->cenarios[this->cenarioAtual].setAtivo(true);
      if(this->cenarioAtual == 2)
      {
        std::cout << "Você terminou o jogo!\nObrigado por jogar!\n";
        this->menuFimJogo->abrir();
        this->cenarios[this->cenarioAtual].setAtivo(false);
      }
    }
  }
}

bool Jogo::moveJogador (int x, int y)
{
  if( x < 0 || x >= this->numColunas || y < 0 || y >= this->numLinhas)
    return false;

  if(this->tilemaps[this->cenarioAtual].andavel(x, y) == false)
  {
	  return false;
  }

  for(int i = 0; i < this->inimigos.size(); i++)
  {
    if(x == this->inimigos[i].getX() && y == this->inimigos[i].getY())
      return false;
  }

  this->jogador.setPosicao(x, y);
  return true;
}

void Jogo::desenhaMenuPause ()
{
}

void Jogo::salvarJogo ()
{
  std::cout << "Salvar jogo não implementado!\n";
}

void Jogo::novoJogo ()
{
  this->inventario = new Inventory(170.,40.);
  Item item("nome", "tipo", 'a', this->window, this->roboto);
  this->inventario->insertItem(item, 0);
  item = Item("nome", "tipo", 'b', this->window, this->roboto);
  this->inventario->insertItem(item, 1);
  item = Item("nome", "tipo", 'c', this->window, this->roboto);
  this->inventario->insertItem(item, 2);

  this->cenarioAtual = 0;
  this->cenarios[this->cenarioAtual].setAtivo(false);
  this->jogador = Jogador(3, 2);
  this->carregaInimigos();
  this->combate = new Combate(this->window, this->tamTile, this->roboto);
}

void Jogo::carregarJogo ()
{
  std::cout << "Carregar jogo não implementado!\n";
}
