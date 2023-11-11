#include "Pieces.hpp"

void Piece::rotate(Tetrimino piece){
  //Serial.println(__FUNCTION__);
  uint8_t aux = (piece == I) ? 4 : 3;
  uint32_t temp[aux][aux];
  for (uint8_t y = 0; y < aux; y++){
    for (uint8_t x = 0; x < aux; x++){
      temp[y][x] = actual_p[aux - x - 1][y];
    }
  }

  for (uint8_t y = 0; y < aux; y++){
    for (uint8_t x = 0; x < aux; x++){
      actual_p[y][x] = temp[y][x];
    }
  }
}

void Piece::init_ap(Tetrimino pa, uint8_t aux){
  for (uint8_t y = 0; y < aux; y++){
    for (uint8_t x = 0; x < aux; x++){
      switch (pa)
      {
        case T:
          actual_p[y][x] = Piece_T[y][x];
        break;
        case I:
          actual_p[y][x] = Piece_I[y][x];
        break;
        case O:
          actual_p[y][x] = Piece_O[y][x];
        break;
        case S:
          actual_p[y][x] = Piece_S[y][x];
        break;
        case Z:
          actual_p[y][x] = Piece_Z[y][x];
        break;
        case J:
          actual_p[y][x] = Piece_J[y][x];
        break;
        case L:
          actual_p[y][x] = Piece_L[y][x];
        break;
      }
    }
  }
}

Piece piece;