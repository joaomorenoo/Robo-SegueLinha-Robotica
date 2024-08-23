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
}

void loop() {
  bool EstadoD = digitalRead(sensorD);
  bool EstadoE = digitalRead(sensorE);
  int Velocidade = 60;

  if (!EstadoD && !EstadoE) {
    analogWrite(motorEN1, Velocidade); 
    analogWrite(motorEN2, 0); 
    analogWrite(motorDN3, Velocidade); 
    analogWrite(motorDN4, 0);
  }
  if (EstadoD && EstadoE) {
    analogWrite(motorEN1, 0); 
    analogWrite(motorEN2, 0); 
    analogWrite(motorDN3, 0); 
    analogWrite(motorDN4, 0); 
  }
  if (!EstadoD && EstadoE) {
    analogWrite(motorEN1, Velocidade); 
    analogWrite(motorEN2, 0); 
    analogWrite(motorDN3, 0); 
    analogWrite(motorDN4, 0); 
  }
  if (EstadoD && !EstadoE){
    analogWrite(motorEN1, 0); 
    analogWrite(motorEN2, 0); 
    analogWrite(motorDN3, Velocidade); 
    analogWrite(motorDN4, 0); 
  }
}