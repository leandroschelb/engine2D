#!/bin/bash

g++ ./src/main.cpp ./src/lib/Combate.cpp ./src/lib/Menu.cpp ./src/lib/Cenario.cpp  ./src/lib/Jogo.cpp ./src/lib/Jogador.cpp ./src/lib/Tilemap.cpp -g -O0 -o engine2D -lsfml-graphics -lsfml-window -lsfml-system

