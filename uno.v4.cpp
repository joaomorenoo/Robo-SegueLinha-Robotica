#include <NewPing.h> 

#define buzzer 7

#define emissorTrig 2
#define receptorEcho 4

NewPing sensorDistancia(emissorTrig, receptorEcho, 100); 

#define sensorE 13
#define sensorD 12

#define motorEN1 11
#define motorEN2 10
#define motorDN3 6
#define motorDN4 5

int segundos = 0;
int minutos = 0;
int inicio = 0;


void setup() {
  pinMode(buzzer, OUTPUT);

  pinMode(sensorE, INPUT);
  pinMode(sensorD, INPUT);

  pinMode(motorEN1, OUTPUT);
  pinMode(motorEN2, OUTPUT);
  pinMode(motorDN3, OUTPUT);
  pinMode(motorDN4, OUTPUT);
}

void loop() {
  cronometro();
  bool EstadoD = digitalRead(sensorD);
  bool EstadoE = digitalRead(sensorE);
  int Velocidade = 60;
  int Distancia = sensorDistancia.ping.cm();
  
  if(Distancia <= 15) {
    inicio = 1;
    analogWrite(motorEN1, 0); 
    analogWrite(motorEN2, 0); 
    analogWrite(motorDN3, 0); 
    analogWrite(motorDN4, 0); 
    tone(buzzer, 900);
    delay(250);
    noTone(buzzer);
    delay(250);
  } else {
        inicio = 0;
        if (!EstadoD && !EstadoE) {
        analogWrite(motorEN1, Velocidade); 
        analogWrite(motorEN2, 0); 
        analogWrite(motorDN3, Velocidade); 
        analogWrite(motorDN4, 0);
        noTone(buzzer);
        }
        if (EstadoD && EstadoE) {
        inicio = 0;    
        analogWrite(motorEN1, 0); 
        analogWrite(motorEN2, 0); 
        analogWrite(motorDN3, 0); 
        analogWrite(motorDN4, 0); 
        noTone(buzzer);
        }
        if (!EstadoD && EstadoE) {
        inicio = 0;    
        analogWrite(motorEN1, Velocidade); 
        analogWrite(motorEN2, 0); 
        analogWrite(motorDN3, 0); 
        analogWrite(motorDN4, 0); 
        noTone(buzzer);
        }
        if (EstadoD && !EstadoE){
        inicio = 0;    
        analogWrite(motorEN1, 0); 
        analogWrite(motorEN2, 0); 
        analogWrite(motorDN3, Velocidade); 
        analogWrite(motorDN4, 0); 
        noTone(buzzer);
        }
    }
}
void cronometro() {
    if (inicio == 1) {
        delay(1000);
        segundos++;
    }
    if (segundos == 60) {
      minutos++;
      segundos = 0;
    }
}