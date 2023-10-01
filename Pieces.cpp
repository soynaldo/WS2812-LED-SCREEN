#include "Pieces.hpp"

void Pieza::rotar_pieza(Tetrimino pieza){
  //Serial.println(__FUNCTION__);
  uint8_t auxiliar = (pieza == I) ? 4 : 3;
  uint32_t temp[auxiliar][auxiliar];
  for (uint8_t y = 0; y < auxiliar; y++){
    for (uint8_t x = 0; x < auxiliar; x++){
      temp[y][x] = pieza_actual[auxiliar - x - 1][y];
    }
  }

  for (uint8_t y = 0; y < auxiliar; y++){
    for (uint8_t x = 0; x < auxiliar; x++){
      pieza_actual[y][x] = temp[y][x];
    }
  }
}

void Pieza::iniciar_pieza_actual(Tetrimino pa, uint8_t auxiliar){
  for (uint8_t y = 0; y < auxiliar; y++){
    for (uint8_t x = 0; x < auxiliar; x++){
      switch (pa)
      {
        case T:
          pieza_actual[y][x] = Pieza_T[y][x];
        break;
        case I:
          pieza_actual[y][x] = Pieza_I[y][x];
        break;
        case O:
          pieza_actual[y][x] = Pieza_O[y][x];
        break;
        case S:
          pieza_actual[y][x] = Pieza_S[y][x];
        break;
        case Z:
          pieza_actual[y][x] = Pieza_Z[y][x];
        break;
        case J:
          pieza_actual[y][x] = Pieza_J[y][x];
        break;
        case L:
          pieza_actual[y][x] = Pieza_L[y][x];
        break;
      }
    }
  }
}