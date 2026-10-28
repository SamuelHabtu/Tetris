#include "tetris.h"

void newPiece()
{
    //todo make this do something
    return;
}

int validPos(Bitboard* piece, Bitboard* state)
{
    for(int i = 0; i < B_HEIGHT; i++){
        if(piece -> columns[i] && state -> columns[i] > 0){
            return 0;
        }
    }
    return 1;
}
void rotate(Bitboard* piece, Bitboard* state)
{
    //TODO MAKE THIS DO SOMETHING
    return;
}

Bitboard initalizeBoard()
{
    Bitboard empty;
    for(int i = 0;i < B_HEIGHT; i++)
    {
        empty.columns[i] = 0;
    }

    return empty;

}