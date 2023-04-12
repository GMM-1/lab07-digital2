/* Nombre: Gabriel Andrade
 *  Carnet: 21499
 *  universidad del valle de Guatemala (Electronica Digital 2)
 *  Laboratorio 7
 */

//************************************************************************************************************************************************************************
//******************************************************************************librerias********************************************************************************* 
//************************************************************************************************************************************************************************
#include <stdint.h>              //libreria de funciones 
#include <ili9341_8_bits_fast.h> //libreria para el uso de pantalla tft
#include "bitmaps.h"             //adjuntamos el archivo con los bitmaps 

//************************************************************************************************************************************************************************
//**************************************************************************variables************************************************************************************* 
//************************************************************************************************************************************************************************
int x = 0; //variable para trackear movimiento horizontal 

//************************************************************************************************************************************************************************
//******************************************************************************setup************************************************************************************* 
//************************************************************************************************************************************************************************
void setup()
{
  //configuramos los pines PA7 y PA3 para los pushes y colocamos pullups internos
  pinMode(PA_7, INPUT_PULLUP);
  pinMode(PE_3, INPUT_PULLUP);

  //asignamos la interrupcion de movimiento de los pushes 
  attachInterrupt(digitalPinToInterrupt(PA_7), mov_right, LOW);
  attachInterrupt(digitalPinToInterrupt(PE_3), mov_left, LOW);

  //configuracion de la comunicacion serial 
  Serial.begin(9600);
  Serial.println("Iniciando pantalla...");

  //configuracion inicial de la pantalla 
  lcdInit(); //inicializacion de la lcd 
  lcdClear(0x1029); //color del fondo 
  
  //dibujamos el fondo
  LCD_Print("LABORATORIO 7", 30, 70, 2, PINK, BLACK); //Titulo del lab
  LCD_Print("BATMAN", 30, 50, 2, PINK, BLACK); //titulo del juego

  //LCD_Bitmap(0, 0, 320, 240, fondo); // bitmap sobrecargado 
  
  //Dibujar estrellas de fondo
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(0, 177, 320, 100, BLACK); //dibujar suelo 
}

//************************************************************************************************************************************************************************
//******************************************************************************ciclo infinito**************************************************************************** 
//************************************************************************************************************************************************************************
void loop()
{}
//************************************************************************************************************************************************************************
//******************************************************************************funciones********************************************************************************* 
//************************************************************************************************************************************************************************

//interrupcion para mover hacia la derecha
void mov_right(){
  delay(5); //delay de funcionamiento 
  while ((digitalRead(PA_7) == LOW) && (x < 320 - 23))
  { //chequeamos las condiciones si se presiona el push adecuado y si no ha llegado al limite en x 
    delay(5); 
    int bat_index = (x/5)%7; //indice para controlar la velocidad
    LCD_Sprite(x++, 148, 23, 26, bat_run, 3, bat_index, 1, 0); //Mostrar imagen
    V_line( x - 1, 148, 30, 0x1029); //Limpiar rastro
    }
  }

  void mov_left(){
  delay(5); //delay de funcionamiento
  while ((digitalRead(PE_3) == LOW) && (x > 0))
  { //chequeamos las condiciones si se presiona el push adecuado y si no ha llegado al limite en x 
    delay(5); 
    int bat_index = (x/5)%7; //indice para controlar la velocidad
    LCD_Sprite(x--, 148, 23, 26, bat_run, 3, bat_index, 0, 0); //Mostrar imagen
    V_line( x + 23, 148, 30, 0x1029); //Limpiar rastro
    }
  }
