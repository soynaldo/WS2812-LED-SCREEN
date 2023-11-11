#ifndef PIECES_TETRIS
#define PIECES_TETRIS

#include <Arduino.h>

// Define las constantes de los colores
#define PIEZA_I 0x005F80 // Azul claro
#define PIEZA_J 0x000080 // Azul oscuro
#define PIEZA_L 0x805200 // Naranja
#define PIEZA_O 0x806000 // Amarillo
#define PIEZA_S 0x008000 // Verde
#define PIEZA_T 0x400080 // Morado
#define PIEZA_Z 0x800000 // Rojo

enum Tetrimino{
  T = 0, I, O, S, Z, J, L
};

class Piece
{   
  public:
    Piece(){}
    ~Piece(){}

    void rotate(Tetrimino piece);
    void init_ap(Tetrimino pa, uint8_t aux);
    uint32_t actual_p[4][4];

    // Matriz de Piece_T
    uint32_t Piece_T[3][3] = {
        {0, PIEZA_T, 0},
        {PIEZA_T, PIEZA_T, PIEZA_T},
        {0, 0, 0}
    };

    // Matriz de Piece_I
    uint32_t Piece_I[4][4] = {
        {0, 0, 0, 0},
        {PIEZA_I, PIEZA_I, PIEZA_I, PIEZA_I},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    // Matriz de Piece_O
    uint32_t Piece_O[3][3] = {
        {PIEZA_O, PIEZA_O, 0},
        {PIEZA_O, PIEZA_O, 0},
        {0, 0, 0}
    };

    // Matriz de Piece_S
    uint32_t Piece_S[3][3] = {
        {0, PIEZA_S, PIEZA_S},
        {PIEZA_S, PIEZA_S, 0},
        {0, 0, 0}
    };

    // Matriz de Piece_Z
    uint32_t Piece_Z[3][3] = {
        {PIEZA_Z, PIEZA_Z, 0},
        {0, PIEZA_Z, PIEZA_Z},
        {0, 0, 0}
    };

    // Matriz de Piece_J
    uint32_t Piece_J[3][3] = {
        {0, 0, PIEZA_J},
        {PIEZA_J, PIEZA_J, PIEZA_J},
        {0, 0, 0}
    };

    // Matriz de Piece_L
    uint32_t Piece_L[3][3] = {
        {PIEZA_L, 0, 0},
        {PIEZA_L, PIEZA_L, PIEZA_L},
        {0, 0, 0}
    };
};

extern Piece piece;

#endif