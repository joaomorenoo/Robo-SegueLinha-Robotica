#include <NewPing.h> 

#define emissorTrig 2
#define receptorEcho 4

#define buzzer 7 

NewPing sensorDistancia(emissorTrig, receptorEcho, 100);

#define sensorE 13
#define sensorD 12

#define motorEN1 11
#define motorEN2 10
#define motorDN3 6
#define motorDN4 5

void setup() {
  pinMode(sensorE, INPUT);
  pinMode(sensorD, INPUT);

  pinMode(motorEN1, OUTPUT);
  pinMode(motorEN2, OUTPUT);
  pinMode(motorDN3, OUTPUT);
  pinMode(motorDN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  bool EstadoD = digitalRead(sensorD);
  bool EstadoE = digitalRead(sensorE);
  int Velocidade = 40;
  int Distancia = sensorDistancia.ping_cm();
  


  if(Distancia >= 5 || Distancia == 0) {
    if (!EstadoD && !EstadoE) {
    analogWrite(motorEN1, 0); 
    analogWrite(motorEN2, Velocidade); 
    analogWrite(motorDN3, Velocidade); 
    analogWrite(motorDN4, 0);
    noTone(buzzer);
    }
    if (EstadoD && EstadoE) {
      analogWrite(motorEN1, 0); 
      analogWrite(motorEN2, 0); 
      analogWrite(motorDN3, 0); 
      analogWrite(motorDN4, 0); 
      noTone(buzzer);
    }
    if (!EstadoD && EstadoE) {
      analogWrite(motorEN1, 0); 
      analogWrite(motorEN2, 0); 
      analogWrite(motorDN3, Velocidade); 
      analogWrite(motorDN4, 0); 
      noTone(buzzer);
    }
    if (EstadoD && !EstadoE){
      analogWrite(motorEN1, 0); 
      analogWrite(motorEN2, Velocidade); 
      analogWrite(motorDN3, 0); 
      analogWrite(motorDN4, 0);
      noTone(buzzer); 
    }
  } else {
    analogWrite(motorEN1, 0); 
    analogWrite(motorEN2, 0); 
    analogWrite(motorDN3, 0); 
    analogWrite(motorDN4, 0); 
    tone(buzzer, 392, 300);
    //delay(100);
    noTone(buzzer);
  }  
}