#include "ScreenClass.hpp"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Pieza tetrimino;
Letras letra;

void Pantalla::init(){
  pixels.begin();
}

void Pantalla::mostrar(){
  //Serial.println(__FUNCTION__);
  pixels.clear();
  for (uint8_t y = 0; y < 16; y+=2) {
    for(uint8_t x = 0; x < 16; x++){
      pixels.setPixelColor(Set_xy(x,y), matriz[y][x]);
      pixels.setPixelColor(Set_nxy(x,(y+1)), matriz[(y+1)][x]);
    }
  }
  pixels.show();
}

void Pantalla::iniciar_pieza(Tetrimino pieza, uint8_t numero_de_rotaciones, uint8_t posicion){
  uint8_t x,y;
  uint8_t aux = (pieza == I) ? 4 : 3;
  tetrimino.iniciar_pieza_actual(pieza, aux);

  if (!(pieza == I && numero_de_rotaciones > 1)){
    while(numero_de_rotaciones--){
      tetrimino.rotar_pieza(pieza);
    }
  }
  for(y = 0; y < aux; y++){
    for(x = 0; x < aux; x++){
      matriz[y][x + posicion] = (tetrimino.pieza_actual[y][x]) ? tetrimino.pieza_actual[y][x] : matriz[y][x + posicion];
    }
  }
  mostrar();
}

void Pantalla::desplazamiento(Direccion direccion){
  //Serial.println(__FUNCTION__);
  switch(direccion)
  {
    case ARRIBA:
      for (uint8_t y = 0; y < 15; y++) {
        for(uint8_t x = 0; x < 16; x++){
          matriz[y][x] = matriz[y+1][x];
          matriz[y+1][x] = 0;
        }
      }
    break;
    case ABAJO:
      for (uint8_t y = 0; y < 15; y++) {
        for(uint8_t x = 0; x < 16; x++){
          matriz[15-y][x] = matriz[14-y][x];
          matriz[14-y][x] = 0;
        }
      }
    break;
    case DERECHA:
      for (uint8_t x = 0; x < 15; x++) {
        for(uint8_t y = 0; y < 16; y++){
          matriz[y][x] = matriz[y][x+1];
          matriz[y][x+1] = 0;
        }
      }
    break;
    case IZQUIERDA:
      for (uint8_t x = 0; x < 15; x++) {
        for(uint8_t y = 0; y < 16; y++){
          matriz[y][15-x] = matriz[y][14-x];
          matriz[y][14-x] = 0;
        }
      }
    break;
  }
}

void Pantalla::mostrar_desplazamiento(Direccion direccion){
  desplazamiento(direccion);
  mostrar();
}

void Pantalla::animacion_tetris(uint8_t repeticion){
  while(repeticion--){
    uint8_t numeroAleatorio = int(random(7));
    uint8_t posicionRandom = int(random(12));
    uint8_t rotacionRandom = int(random(2));

    switch (numeroAleatorio){
      case 0:
      iniciar_pieza(T, rotacionRandom, posicionRandom);
      break;
      case 1:
      delay(100);
      mostrar_desplazamiento(ABAJO);
      iniciar_pieza(I, rotacionRandom, posicionRandom);
      break;
      case 2:
      iniciar_pieza(O, rotacionRandom, posicionRandom);
      break;
      case 3:
      iniciar_pieza(S, rotacionRandom, posicionRandom);
      break;
      case 4:
      iniciar_pieza(Z, rotacionRandom, posicionRandom);
      break;
      case 5:
      iniciar_pieza(J, rotacionRandom, posicionRandom);
      break;
      case 6:
      iniciar_pieza(L, rotacionRandom, posicionRandom);
      break;
    }
    delay(100);
    mostrar_desplazamiento(ABAJO);
    delay(100);
    mostrar_desplazamiento(ABAJO);
    delay(100);
    mostrar_desplazamiento(ABAJO);
  }
}

void Pantalla::mostrar_frase(String frase){
  uint8_t a = 0;
  while(frase[a]){
    iniciar_letra(frase[a], 0x010000);
    a++;
  }
}

void Pantalla::iniciar_letra(char caracter, uint32_t color){
  letra.cargar_letra(letra.decodificar_caracter(caracter), color);
  for (uint8_t a = 0; a < 8; a++){
    
    for(uint8_t y = 0; y < 10; y++){
      matriz[y+3][0] = letra.caracter_actual[y][0];
    }  
    
    for (uint8_t x = 0; x < 7; x++) {
      for(uint8_t y = 0; y < 10; y++){
        letra.caracter_actual[y][x] = letra.caracter_actual[y][x+1];
        letra.caracter_actual[y][x+1] = 0;
      }
    }
    mostrar();
    desplazamiento(IZQUIERDA);
    delay(100);
  }

}
