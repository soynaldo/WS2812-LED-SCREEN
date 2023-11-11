#include "ScreenClass.hpp"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void Screen::init(){
  pixels.begin();
}

void Screen::show(){
  //Serial.println(__FUNCTION__);
  pixels.clear();
  for (uint8_t y = 0; y < 16; y+=2) {
    for(uint8_t x = 0; x < 16; x++){
      pixels.setPixelColor(Set_xy(x,y), _mt[y][x]);
      pixels.setPixelColor(Set_nxy(x,(y+1)), _mt[(y+1)][x]);
    }
  }
  pixels.show();
}

void Screen::init_piece(Tetrimino piece, uint8_t rotation_number, uint8_t position){
  uint8_t x,y;
  uint8_t aux = (piece == I) ? 4 : 3;
  piece.init_ap(piece, aux);

  if (!(piece == I && rotation_number > 1)){
    while(rotation_number--){
      piece.rotate(piece);
    }
  }
  for(y = 0; y < aux; y++){
    for(x = 0; x < aux; x++){
      _mt[y][x + position] = (piece.actual_p[y][x]) ? piece.actual_p[y][x] : _mt[y][x + position];
    }
  }
  show();
}

void Screen::move(Direccion direction){
  //Serial.println(__FUNCTION__);
  switch(direction)
  {
    case ARRIBA:
      for (uint8_t y = 0; y < 15; y++) {
        for(uint8_t x = 0; x < 16; x++){
          _mt[y][x] = _mt[y+1][x];
          _mt[y+1][x] = 0;
        }
      }
    break;
    case ABAJO:
      for (uint8_t y = 0; y < 15; y++) {
        for(uint8_t x = 0; x < 16; x++){
          _mt[15-y][x] = _mt[14-y][x];
          _mt[14-y][x] = 0;
        }
      }
    break;
    case DERECHA:
      for (uint8_t x = 0; x < 15; x++) {
        for(uint8_t y = 0; y < 16; y++){
          _mt[y][x] = _mt[y][x+1];
          _mt[y][x+1] = 0;
        }
      }
    break;
    case IZQUIERDA:
      for (uint8_t x = 0; x < 15; x++) {
        for(uint8_t y = 0; y < 16; y++){
          _mt[y][15-x] = _mt[y][14-x];
          _mt[y][14-x] = 0;
        }
      }
    break;
  }
}

void Screen::move_and_show(Direccion direction){
  move(direction);
  show();
}

void Screen::init_phrase(const char* phr, Direccion dir, Mode mode, uint32_t color){
  _phrase = phr;
  _letter_color = color;
  _phrase_dir = dir;
  _phrase_mode = mode;
}

void Screen::update_phrase(const char* phr){
  _phrase.clear();
  _phrase = phr;
}

void Screen::tetris_animation(uint8_t repeticion){
  while(repeticion--){
    uint8_t random_number = int(random(7));
    uint8_t random_position = int(random(12));
    uint8_t random_rotation = int(random(2));

    switch (random_number){
      case 0:
      init_piece(T, random_rotation, random_position);
      break;
      case 1:
      delay(100);
      move_and_show(ABAJO);
      init_piece(I, random_rotation, random_position);
      break;
      case 2:
      init_piece(O, random_rotation, random_position);
      break;
      case 3:
      init_piece(S, random_rotation, random_position);
      break;
      case 4:
      init_piece(Z, random_rotation, random_position);
      break;
      case 5:
      init_piece(J, random_rotation, random_position);
      break;
      case 6:
      init_piece(L, random_rotation, random_position);
      break;
    }
    delay(100);
    move_and_show(ABAJO);
    delay(100);
    move_and_show(ABAJO);
    delay(100);
    move_and_show(ABAJO);
  }
}

void Screen::handle_phrase(){
  uint8_t a = 0;
  while (_phrase[a]){
    switch _phrase_mode
    {
      case MULTICOLOR: 
        uint8_t random_color = random(0,9);
        init_letter(_phrase[a], _multicolors[random_color]);
        break;

      case LETTER_MULTICOLOR: 
        init_letter(_phrase[a], 0, true);
        break;

      case LETTER_MULTICOLOR_TETRIS: 
        uint8_t random_color = random(0,7);
        init_letter(_phrase[a], _tetris_multicolors[random_color]);
        break;

      default: 
        init_letter(_phrase[a], _letter_color);
        break;
    }
    a++;
  }
}

void Screen::init_letter(char ch, uint32_t color, bool letter_multicolor){
  if (letter_multicolor){
    uint8_t random_color = random(0,9);
    letter.bring_letter(letter.decode_ch(ch), _multicolors[random_color]);
  }else {
    letter.bring_letter(letter.decode_ch(ch), color);
  }
  
  for (uint8_t a = 0; a < 8; a++){
    
    for(uint8_t y = 0; y < 10; y++){
      _mt[y+3][0] = letter.actual_ch[y][0];
    }  
    
    for (uint8_t x = 0; x < 7; x++) {
      for(uint8_t y = 0; y < 10; y++){
        letter.actual_ch[y][x] = letter.actual_ch[y][x+1];
        letter.actual_ch[y][x+1] = 0;
      }
    }
    show();
    move(_phrase_dir);
    delay(100);
  }
}

Screen screen;