#include "../include/Inventory.hpp"

Inventory::Inventory(float x, float y)
{
  this->open = false;
  this->check_selected_slot = false;
  this->x = x;
  this->y = y;

  this->rectangle.setSize(sf::Vector2f(300.f,180.f));
  this->rectangle.setFillColor(sf::Color(128,128,128));

  if(!this->equipFont.loadFromFile("data/fonts/Roboto/Roboto-Regular.ttf")) //fazer uso do try-catch aqui!
    std::cout << "loading equipFont ERROR\n";

  for(int i = 0; i < 5; i++)
  {
    this->equips[i].setSize(sf::Vector2f(25.f, 25.f));
    this->equips[i].setFillColor(sf::Color(255, 255, 255));
    this->equipName[i].setFont(equipFont);
    this->equipName[i].setCharacterSize(10);
    this->equipName[i].setFillColor(sf::Color(0, 0, 0));
    this->equipName[i].setStyle(sf::Text::Regular);
  }

  this->equipName[0].setString("Head");
  this->equipName[1].setString("Body");
  this->equipName[2].setString("Legs");
  this->equipName[3].setString("Main");
  this->equipName[4].setString("Off");

  for(int i = 0;i < 9; i++)
  {
    this->slots[i].setSize(sf::Vector2f(25.f, 25.f));
    this->slots[i].setFillColor(sf::Color(255,255,255));
  }
}

void Inventory::insertItem(Item item, int slot)
{
  item.setSlotAtual(slot);
  this->itens.push_back(item);
}

void Inventory::setOpen(bool status) //abrir inventario
{
  this->open = status;
}

bool Inventory::getOpen() //fechar inventario(deve ser colocado como condicao de um if)
{
  return this->open;
}

void Inventory::position(float x, float y) //posicao x e y do inventario em si(a partir de onde sera desenhado),
{                                          //o seu conteudo(equips e slots) sera posicionado de acordo com estes valores
  this->rectangle.setPosition(sf::Vector2f(x,y));
  float initial_y; //para colocar o primeiro equip(head) e, a partir dessa posicao, colocar os 2 equips abaixo(body,legs)
  initial_y = y + 10;
  for(int i = 0; i < 3; i++)
  {
    this->equips[i].setPosition((float)(x + 137.5f), (float)(initial_y + 35*i));
    this->equipName[i].setPosition((float)(x + 140.75f), (float)(initial_y + 35*i));
  }

  this->equips[3].setPosition((x + 102.5f), (y + 45.f));
  this->equipName[3].setPosition((x + 105.75f), (y + 45.f));
  this->equips[4].setPosition((x + 172.5f), (y + 45.f));
  this->equipName[4].setPosition((x + 175.75f), (y + 45.f));

  float initial_x; //para colocar o primeiro slot e, a partir dessa posicao, colocar os outros slots
  initial_x = x + 17.5f;
  for(int i = 0; i < 9; i++)
    this->slots[i].setPosition((float)(initial_x + 30*i), (y + 145.f));
}

void Inventory::draw(sf::RenderWindow& window)
{
  float x = this->x;
  float y = this->y;
  this->position(x, y);
  window.draw(this->rectangle);
  for(int i = 0; i < 5; i++)
    window.draw(this->equips[i]);

  for(int i = 0; i < 9; i++)
    window.draw(this->slots[i]);
  int initial_x = x + 18.75f;
  int initial_y = y + 11.25f;
  for(auto it = this->itens.begin(); it != this->itens.end(); it++)
  {
    if(it->getSlotAtual() < 9)
      it->desenha((float)(initial_x + 30*it->getSlotAtual()), (float)(y + 146.25f));
    if((it->getSlotAtual() > 9) and (it->getSlotAtual() < 13)) // 10-head, 11-body, 12-legs
      it->desenha((float)(x + 138.75f), (float)(initial_y + 35*(it->getSlotAtual() - 10)));
    if(it->getSlotAtual() == 13) // 13- main-hand
      it->desenha((x + 103.75f), (y + 46.25f));
    if(it->getSlotAtual() == 14) // 14- off-hand
      it->desenha((x + 173.75f), (y + 46.25f));
  }
  for(int i = 0; i < 5; i++)
    window.draw(this->equipName[i]);
}

void Inventory::swapSlotItens(int i, int j)
{
  for(std::vector<Item>::iterator it = this->itens.begin(); it != this->itens.end(); it++)
  {
    if(it->getSlotAtual() == i)
      it->setSlotAtual(j);
    else
    if(it->getSlotAtual() == j)
      it->setSlotAtual(i);
  }

  this->slots[j].setFillColor(sf::Color::White);
}

void Inventory::equipItem(int i_slot, int i_equip)
{
  for(std::vector<Item>::iterator it = this->itens.begin(); it != this->itens.end(); it++)
  {
    if(it->getSlotAtual() == i_slot)
      it->setSlotAtual(i_equip);
    else
    if(it->getSlotAtual() == i_equip)
      it->setSlotAtual(i_slot);
  }
  //this->equips[i_equip].setFillColor(this->slots[i_slot].getFillColor());
  this->slots[i_slot].setFillColor(sf::Color::White);
}

bool Inventory::mouseContido (int mx, int my, int ix, int iy)
{
   return mx > ix && mx < ix +300 && my > iy + 145 && my < iy +170;
}

void Inventory::clickEvent(sf::Event& event) //x e y do inventario(canto superior esquerdo do retangulo)
{
  int j_slot, i_equip;
  float x = this->x, y = this->y, mx = event.mouseButton.x, my = event.mouseButton.y;
  if(this->mouseContido(mx, my, int(x), int(y)))
  {
    for(this->i_slot = 0; this->i_slot < 9; this->i_slot++)
    {
      sf::RectangleShape* slot= &this->slots[this->i_slot];
      if( mx > slot->getPosition().x && mx < slot->getPosition().x + 25 && my > slot->getPosition().y && my < slot->getPosition().y + 25 )
      {
        if(slot->getFillColor().g != 0) //se nao estiver vermelho(selecionado)
        {
          if(this->check_selected_slot == false) //e nao tiver nenhum slot vermelho(selecionado)
          {
            this->check_selected_slot = true;
            slot->setFillColor(sf::Color(255,0,0)); //colore slot de vermelho(seleciona)
          }
          else //e tiver um slot vermelho(selecionado), faco a "troca" deles(na troca real eu nao vou deixar nenhum slot vermelho apos a troca)
          {
            for(j_slot = 0; j_slot < 9; j_slot++)
              if(slots[j_slot].getFillColor().g == 0)
                break;
            this->swapSlotItens(this->i_slot, j_slot); //aqui o this->i_slot vai ser o segundo slot que vc clicou(o nao vermelho)
            j_slot = this->i_slot;
            this->check_selected_slot = false;
          }
          break;
        }
      }
    }
  }
  if( mx > x+102 && mx < x+200 && my > y+10 && my < y+110 )
  {
    if(this->check_selected_slot == true) //se tiver um slot selecionado
    {
      for(i_equip = 0; i_equip < 5; i_equip++) //ache o equips clicado
      {
        if( (mx > this->equips[i_equip].getPosition().x) and
            (mx < (this->equips[i_equip].getPosition().x + 25)) and
            (my > this->equips[i_equip].getPosition().y) and
            (my < (this->equips[i_equip].getPosition().y + 25)) )
        {
          if(this->equips[i_equip].getFillColor().g != 0) //se o equip nao estiver vermelho("equipado")
          {
            i_equip = i_equip + 10; //a funcao draw do inventory usa numeros de 10 a 14 para desenhar itens nos equips
            //std::cout << "this->i_slot no equip: " << this->i_slot << std::endl;
            this->equipItem(this->i_slot, i_equip); //aqui o this->i_slot vai ser o primeiro item que voce clicou
            this->check_selected_slot = false;
          }
          break;
        }
      }
    }
  }
}
