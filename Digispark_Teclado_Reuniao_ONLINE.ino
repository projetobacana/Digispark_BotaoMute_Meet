/* *************************
 *  Projeto Bacana - 09/2021
 *  www.projetobacana.com.br
 *  Júlio Vansan Gonçalves
 *  Principais teclas que podem ser usadas:
 *  MOD_CONTROL_LEFT
 *  MOD_SHIFT_LEFT
 *  MOD_ALT_LEFT
 *  MOD_CONTROL_RIGHT
 *  MOD_SHIFT_RIGHT
 *  MOD_ALT_RIGHT
 *  
 *  Teclas de A até Z = KEY_A, KEY_B ... KEY_Z
 *  Números = KEY_0, KEY_1 ... KEY_9
 *  Teclas de Função = KEY_F1, KEY_F2 ... KEY_F12
 *  
 *  ************************
 */

#include "DigiKeyboard.h"

int botaoSom = 0;
const int LED=1;

void setup() {
  pinMode(botaoSom,INPUT_PULLUP);
  pinMode(LED,OUTPUT);

  DigiKeyboard.sendKeyStroke(0); //Garantir que Nada será enviado por engano
  DigiKeyboard.delay(500);
  
}

void loop() {
  delay(50);
  if (digitalRead(botaoSom)==LOW){
    digitalWrite(LED,HIGH);
    DigiKeyboard.sendKeyStroke(0);//Garantir que Nada será enviado por engano
    DigiKeyboard.delay(100); 
//    DigiKeyboard.sendKeyStroke(KEY_D, MOD_CONTROL_LEFT); // Google Meet
    DigiKeyboard.sendKeyStroke(KEY_M, MOD_SHIFT_LEFT | MOD_CONTROL_LEFT | MOD_ALT_LEFT); // Microsoft Teams
//    DigiKeyboard.sendKeyStroke(KEY_A, MOD_ALT_LEFT); // Zoom
    delay(50);
    while (digitalRead(botaoSom)==LOW){
        delay(50); //espera até o botão não estiver pressoinado
    }//while  
    digitalWrite(LED,LOW);  
  } //if botão do som

}// loop
