#include "ScreenClass.hpp"
#include "Pieces.hpp"
#include "TetrisClass.hpp"
#include "LettersClass.hpp"

Pantalla pantalla;
String frase;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pantalla.init();
}

void loop() {
  //pantalla.animacion_tetris(10);
  pantalla.mostrar_frase(frase);
  if (Serial.available()){
    frase = Serial.readStringUntil('\n');
  }
}