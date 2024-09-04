#define emissorTrig 2
#define receptorEcho 4

#define sensorE 13
#define sensorD 12

#define motorEN1 11
#define motorEN2 10
#define motorDN3 6
#define motorDN4 5

long duracao;
int distancia;

void setup() {
  pinMode(sensorE, INPUT);
  pinMode(sensorD, INPUT);

  pinMode(motorEN1, OUTPUT);
  pinMode(motorEN2, OUTPUT);
  pinMode(motorDN3, OUTPUT);
  pinMode(motorDN4, OUTPUT);

  pinMode(emissorTrig, OUTPUT);
  pinMode(receptorEcho, INPUT)

  Serial.begin(9600);
}

void loop() {
  bool EstadoD = digitalRead(sensorD);
  bool EstadoE = digitalRead(sensorE);
  int Velocidade = 40;
  calc_dist();

  if(distancia >= 5 || distancia == 0) {
    if (!EstadoD && !EstadoE) {
    analogWrite(motorEN1, 0); 
    analogWrite(motorEN2, Velocidade); 
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
      analogWrite(motorEN1, 0); 
      analogWrite(motorEN2, 0); 
      analogWrite(motorDN3, Velocidade); 
      analogWrite(motorDN4, 0);
    }
    if (EstadoD && !EstadoE){
      analogWrite(motorEN1, 0); 
      analogWrite(motorEN2, Velocidade); 
      analogWrite(motorDN3, 0); 
      analogWrite(motorDN4, 0); 
    }
  } else {
    analogWrite(motorEN1, 0); 
    analogWrite(motorEN2, 0); 
    analogWrite(motorDN3, 0); 
    analogWrite(motorDN4, 0); 
  }  
}
void calc_dist() {
  digitalWrite(emissorTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(emissorTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(emissorTrig, LOW);
  duracao = pulseIn(receptorEcho, HIGH);
  distancia = duracao * 0.034 / 2;
}
/*void musica(){
  tone(3,440); // Do
  delay (150); 
  tone(3,494); // Re
  delay (150); 
  tone(3,523); // Mi
  delay (150);
  tone(3,587); // Fa
  delay (150);
  tone(3,659); // Sol
  delay (150);
  tone(3,698); // La
  delay (150);
  tone(3,784); // Si
  delay (150);
} */ 
