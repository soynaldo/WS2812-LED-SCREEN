#include "LettersClass.hpp"

void Letras::cargar_letra(uint8_t posicion_caracter, uint32_t color){
  for (uint8_t y = 0; y < 10; y++){
    for (uint8_t x = 0; x < 8; x++){
      caracter_actual[y][x] = bitRead((caracteres_led[posicion_caracter][y]), x) ? color : 0; 
    }
  }
}

uint8_t Letras::decodificar_caracter(char caracter){
  switch(caracter){
    case '0':return 0;break;
    case '1':return 1;break;
    case '2':return 2;break;
    case '3':return 3;break;
    case '4':return 4;break;
    case '5':return 5;break;
    case '6':return 6;break;
    case '7':return 7;break;
    case '8':return 8;break;
    case '9':return 9;break;
    case 'A':return 10;break;
    case 'Á':return 10;break;
    case 'B':return 11;break;
    case 'C':return 12;break;
    case 'D':return 13;break;
    case 'E':return 14;break;
    case 'É':return 14;break;
    case 'F':return 15;break;
    case 'G':return 16;break;
    case 'H':return 17;break;
    case 'I':return 18;break;
    case 'Í':return 18;break;
    case 'J':return 19;break;
    case 'K':return 20;break;
    case 'L':return 21;break;
    case 'M':return 22;break;
    case 'N':return 23;break;
    case 'O':return 24;break;
    case 'Ó':return 24;break;
    case 'P':return 25;break;
    case 'Q':return 26;break;
    case 'R':return 27;break;
    case 'S':return 28;break;
    case 'T':return 29;break;
    case 'U':return 30;break;
    case 'Ú':return 30;break;
    case 'V':return 31;break;
    case 'W':return 32;break;
    case 'X':return 33;break;
    case 'Y':return 34;break;
    case 'Z':return 35;break;
    case '_':return 36;break;
    case '.':return 37;break;
    case ',':return 38;break;
    case ':':return 39;break;
    case ';':return 40;break;
    case '!':return 41;break;
    case '+':return 42;break;
    case '-':return 43;break;
    case '=':return 44;break;
    case '?':return 45;break;
    case '(':return 46;break;
    case ')':return 47;break;
    case 'a':return 10;break;
    case 'á':return 10;break;
    case 'b':return 11;break;
    case 'c':return 12;break;
    case 'd':return 13;break;
    case 'e':return 14;break;
    case 'é':return 14;break;
    case 'f':return 15;break;
    case 'g':return 16;break;
    case 'h':return 17;break;
    case 'i':return 18;break;
    case 'í':return 18;break;
    case 'j':return 19;break;
    case 'k':return 20;break;
    case 'l':return 21;break;
    case 'm':return 22;break;
    case 'n':return 23;break;
    case 'o':return 24;break;
    case 'ó':return 24;break;
    case 'p':return 25;break;
    case 'q':return 26;break;
    case 'r':return 27;break;
    case 's':return 28;break;
    case 't':return 29;break;
    case 'u':return 30;break;
    case 'ú':return 30;break;
    case 'v':return 31;break;
    case 'w':return 32;break;
    case 'x':return 33;break;
    case 'y':return 34;break;     
    case 'z':return 35;break; 
  }
}