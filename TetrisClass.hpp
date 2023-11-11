#ifndef TETRIS
#define TETRIS

#include <Arduino.h>
#include "ScreenClass.hpp"

class Tetris
{
    private:
    uint32_t _mt_cmp[HEIGHT][WIDTH];
    uint32_t puntuation;
    
    public:
    Tetris();
    ~Tetris(){}
    bool can_move(Direccion dir);
    uint32_t get_puntuation();
    
};

extern Tetris tetris;

#endif
