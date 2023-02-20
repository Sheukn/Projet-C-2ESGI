all:
	gcc -o game main.c -L lib -lSDL -lSDL_image -lSDL_ttf -lm