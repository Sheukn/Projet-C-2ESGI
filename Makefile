all:
	gcc -o game main.c -I include -L lib -lmingw32 -lSDL2main -lSDL2