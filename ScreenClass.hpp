#ifndef SCREEN_CLASS
#define SCREEN_CLASS

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include "Pieces.hpp"
#include "LettersClass.hpp"

//Caracteristicas de la matriz y el pin que utilizara
#define PIN 2
#define NUMPIXELS 256
#define HEIGHT 16
#define WIDTH 16

//Macros para algunas operaciones
#define Set_xy(x,y) ((WIDTH * y ) + x) 
#define Set_nxy(x,y) ((WIDTH * y ) +(15 - x))

enum Direccion{
  ARRIBA, ABAJO, IZQUIERDA, DERECHA
};

class Pantalla
{
  private:
    uint32_t matriz[HEIGHT][WIDTH]; 

  public:
    Pantalla(){}
    void init();
    void desplazamiento(Direccion direccion);
    void mostrar_desplazamiento(Direccion direccion);
    void mostrar_frase(String frase);
    void iniciar_letra(char caracter, uint32_t color);
    void animacion_tetris(uint8_t repeticion);
    void mostrar(void);
    void iniciar_pieza(Tetrimino pieza, uint8_t numero_de_rotaciones, uint8_t posicion);
};

#endif