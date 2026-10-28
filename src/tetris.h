#ifndef TETRIS_H
#define TETRIS_H
#include <stdint.h>
#define B_WIDTH 10
#define B_HEIGHT 20
#define P_WIDTH 4
#define P_HEIGHT 4


typedef struct
{
    //each element of bitboard will represent one column of the entire potential board
    int columns[B_HEIGHT];

}Bitboard;

void newPiece();//spawns new piece every ... frames might get crazy and have them spawn randomly rotated 
int validPos(Bitboard *piece, Bitboard* state);
void rotate(Bitboard *piece, Bitboard* state); //use the address to edit the piece-> typing rotate(piece) is way nicer than piece = rotate(piece)
//we define the piece bitboards(in their default state before rotation) -> O, I, S, Z, L, J, T they will be 4x4 bitboards(16 bits)
/*                Array                                'Piece'                      Bit-board value                                 
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},  // I -> 2^4 + 2^5 + 2^6 +2^7 = 16 + 32 + 64 + 128 = 240
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},  // O -> 2^5 + 2^6 + 2^9 + 2^10 = 32 + 64 +512 + 1024 = 1632
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0},  // S -> 2^6 + 2^7 + 2^9 + 2^10 = 1728
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},  // Z -> 2^4 + 2^5 + 2^9 + 2^10 = 1584
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},  // T -> 2^5 + 2^8 + 2^9 + 2^10 = 1824
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},  // L -> 2^4 + 2^8 + 2^9 + 2^10 = 1808
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0}   // J -> 2^7 + 2^9 + 2^10 + 2^11 = 3712
*/
Bitboard initalizeBoard();



#endif