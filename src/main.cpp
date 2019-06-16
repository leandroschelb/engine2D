#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include "./include/Jogo.hpp"
#include "./include/Tilemap.hpp"
#include "./include/Cenario.hpp"

int main()
{
  std::srand((unsigned) time(NULL));
  sf::RenderWindow* w = new sf::RenderWindow(sf::VideoMode(640, 480), "The legend of Jeremias");
  Jogo jogo(w);
  Jogo jogo2 = jogo;
  int frameRate = 60;
  jogo2.gameLoop(frameRate);
  return 0;
}
