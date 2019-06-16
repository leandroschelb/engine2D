CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -g
CFILES = ./src/main.cpp \
         ./src/lib/Cenario.cpp \
         ./src/lib/Jogo.cpp \
         ./src/lib/Tilemap.cpp \
         ./src/classes/desenhavel/desenhavel.cpp \
         ./src/classes/desenhavel/animado/animado.cpp \
         ./src/classes/desenhavel/animado/jogador/jogador.cpp \
         ./src/classes/desenhavel/animado/inimigo/inimigo.cpp \
         ./src/lib/Menu.cpp \
         ./src/lib/Combate.cpp \
				 ./src/lib/Inventory.cpp \
				 ./src/lib/Item.cpp

TESTFILES = ./testes/TesteJogador.cpp \
            ./testes/TesteDesenhavel.cpp \
			      ./testes/TesteInimigo.cpp \
            ./testes/TesteTilemap.cpp \
            ./testes/TesteCenario.cpp \
            ./src/classes/desenhavel/desenhavel.cpp \
            ./src/classes/desenhavel/animado/animado.cpp \
            ./src/classes/desenhavel/animado/jogador/jogador.cpp \
            ./src/classes/desenhavel/animado/inimigo/inimigo.cpp \
            ./src/lib/Tilemap.cpp \
            ./src/lib/Cenario.cpp

TESTFLAGS = --coverage

engine2D: $(CFILES)
	$(CC) -o $@ $(CFILES) -O0 $(CFLAGS)

release: $(CFILES)
	$(CC) -o $@ $(CFILES) -O3 $(CFLAGS)

test: $(CFILES) $(TESTFILES)
	$(CC) -o $@ $(TESTFILES) $(CFLAGS) $(TESTFLAGS)

clean:
	rm -f engine2D
	rm -f release
	rm -f test
	rm -f *.gcda
	rm -f *.gcno
	rm -f vgcore*
