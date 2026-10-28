#include <stdio.h>
#include <time.h>
#include "tetris.h"
#include "input.h"

void processInputs(Bitboard * piece, Bitboard *board)
{
        if(!_kbhit()){
                return;
        }
        else{
                int key =  getchar();
                printf("%d, key pressed!", key);
                return;
        }

}

int main(void){

        unsigned score = 0;
        int cur_index = 0;
        int game_cont = 1;
        Bitboard board = initalizeBoard();
        Bitboard active = initalizeBoard();
        active.columns[0] = 11;
        printf("\e[2J\e[H"); //clear screen and reset where you are
        const int targetFrameTime = 16;
        clock_t last_time = clock();
        clock_t now;
        clock_t elapsed;
        while(game_cont)
        {
                now = clock();
                elapsed = (now - last_time);
                processInputs(&active, &board);
                last_time = now;
        }       
        return 0;
}