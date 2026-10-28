cc = gcc
flags = -Wall -std=c99
Tetris: game.o tetris.o input.o
	$(cc) $(flags) $^ -o $@
game.o: game.c tetris.h input.h
	$(cc) $(flags) -c $< -o $@
tetris.o: tetris.c tetris.h
	$(cc) $(flags) -c $< -o $@
input.o: input.c input.h 
	$(cc) $(flags) -c $< -o $@
render: render.c
	$(cc) `pkg-config --cflags gtk4` $< -o $@ `pkg-config --libs gtk4`



.Phoney: clean
clean: Tetris
	rm -r -f *.o
	
