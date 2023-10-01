#ifndef LETTERS_LED
#define LETTERS_LED

#include <Arduino.h>

class Letras
{
  private:
    const char caracteres_led[48][10] = { //mini base de datos de cada caracter
      {62,99,103,103,107,115,115,99,62,0},//0
      {12,14,15,12,12,12,12,12,63,0},     //1
      {30,51,51,48,24,12,6,3,63,0},       //2
      {30,51,51,48,24,48,51,51,30,0},     //3
      {48,48,51,51,51,51,127,48,48,0},    //4
      {63,3,3,31,48,48,48,51,30,0},       //5
      {30,51,3,31,51,51,51,51,30,0},      //6
      {63,48,24,24,12,6,6,3,3,0},         //7
      {30,51,51,51,30,51,51,51,30,0},     //8
      {30,51,51,51,51,30,48,51,30,0},     //9
      {8,28,54,99,99,127,99,99,99,0},     //A
      {63,99,99,99,63,99,99,99,63,0},     //B
      {62,99,3,3,3,3,3,99,62,0},          //C
      {31,51,99,99,99,99,99,51,31,0},     //D
      {127,3,3,3,63,3,3,3,127,0},         //E
      {127,3,3,3,63,3,3,3,3,0},           //F
      {62,99,3,3,123,99,99,99,94,0},      //G
      {99,99,99,99,127,99,99,99,99,0},    //H
      {30,12,12,12,12,12,12,12,30,0},     //I
      {96,96,96,96,96,99,99,99,62,0},     //J
      {99,51,51,15,7,15,27,51,99,0},      //K
      {3,3,3,3,3,3,3,3,127,0},            //L
      {99,119,127,107,99,99,99,99,99,0},  //M
      {99,99,103,111,123,115,99,99,99,0}, //N
      {62,99,99,99,99,99,99,99,62,0},     //O
      {63,99,99,99,99,63,3,3,3,0},        //P
      {62,99,99,99,99,99,123,62,96,0},    //Q
      {63,99,99,99,99,63,27,51,99,0},     //R
      {62,99,3,3,62,96,96,99,62,0},       //S
      {127,89,24,24,24,24,24,24,60,0},    //T
      {99,99,99,99,99,99,99,99,62,0},     //U
      {99,99,99,99,99,99,54,28,8,0},      //V
      {99,99,99,99,107,127,119,99,99,0},  //W
      {99,99,99,54,28,54,99,99,99,0},     //X
      {99,99,99,54,60,24,24,24,24,0},     //Y
      {63,48,24,24,12,6,6,3,63,0},        //Z
      {0,0,0,0,0,0,0,0,0,0},              //espacio
      {0,0,0,0,0,0,0,48,48},              //.
      {0,0,0,0,0,0,48,48,32,16},          //,
      {0,0,0,0,48,48,0,48,48,0},          //:
      {0,0,0,0,48,48,0,48,48,24},         //;
      {48,48,48,48,48,48,0,48,48,0},      //!
      {0,12,12,127,127,12,12,0,0},        //+
      {0,0,0,0,62,62,0,0,0},              //-
      {0,0,0,63,0,63,0,0,0},              //=
      {30,51,51,48,24,12,0,12,12},        //?
      {12,6,6,6,6,6,6,6,12,0},              //(
      {24,48,48,48,48,48,48,48,24,0}};      //)
  public:
    Letras(){}
    uint32_t caracter_actual[10][8];
    void cargar_letra(uint8_t posicion_caracter, uint32_t color);
    uint8_t decodificar_caracter(char caracter);
};

#endif