#ifndef SCREEN_CLASS
#define SCREEN_CLASS

#include <Arduino.h>
#include "Pieces.hpp"
#include "LettersClass.hpp"

#define BLUE 0x000080
#define CYAN 0x008080
#define GREEN 0x008000
#define YELLOW 0x808000
#define ORANGE 0x805200
#define RED 0x800000
#define ROSE 0x800080
#define VIOLET 0x400080
#define WHITE 0x808080
#define GRAY 0x303030

//Caracteristicas de la matriz y el pin que utilizara
#define PIN 2
#define NUMPIXELS 256
#define HEIGHT 16
#define WIDTH 16

//Macros para algunas operaciones
#define Set_xy(x,y) ((WIDTH * y ) + x) 
#define Set_nxy(x,y) ((WIDTH * y ) +(HEIGHT - 1 - x))

enum Direccion{
  ARRIBA, ABAJO, IZQUIERDA, DERECHA
};

enum Mode{
  NORMAL,
  MULTICOLOR,
  LETTER_MULTICOLOR,
  LETTER_MULTICOLOR_TETRIS
};

class Screen
{
  private:
    uint32_t _mt[HEIGHT][WIDTH]; 
    Mode _phrase_mode;
    String _phrase;
    uint32_t _letter_color;
    Direccion _phrase_dir;
    uint32_t _multicolors[9] = {BLUE, CYAN, GREEN, YELLOW, ORANGE, RED, VIOLET, ROSE, WHITE};
    uint32_t _tetris_multicolors[7] = {PIEZA_I, PIEZA_J, PIEZA_L, PIEZA_O, PIEZA_S, PIEZA_T, PIEZA_Z};

  public:
    Screen(){}
    ~Screen(){}
    void init();
    void move(Direccion direction);
    void move_and_show(Direccion direction);
    void init_phrase(const char* phr, Direccion dir, Mode mode, uint32_t color = 0);
    void update_phrase(const char* phr);
    void handle_phrase();
    void init_letter(char ch, uint32_t color, bool letter_multicolor = false);
    void tetris_animation(uint8_t repeticion);
    void show(void);
    void init_piece(Tetrimino piece, uint8_t rotation_number, uint8_t position);

};

extern Screen screen;

#endif