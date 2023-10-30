int led = 13;
int pitidoCorto = 500;
int pitidoLargo = 1000;
int pausa = 2000;

void setup() {                
  pinMode(led, OUTPUT);     
}

void loop() {
  
  // letra S
  digitalWrite(led, HIGH);
  delay(pitidoCorto);
  digitalWrite(led, LOW);
  delay(pitidoCorto);
  digitalWrite(led, HIGH);
  delay(pitidoCorto);
  digitalWrite(led, LOW);
  delay(pitidoCorto);
  digitalWrite(led, HIGH);
  delay(pitidoCorto);
  digitalWrite(led, LOW);
  delay(pitidoCorto);
  
  
  // letra O
  digitalWrite(led, HIGH);
  delay(pitidoLargo);
  digitalWrite(led, LOW);
  delay(pitidoLargo);
  digitalWrite(led, HIGH);
  delay(pitidoLargo);
  digitalWrite(led, LOW);
  delay(pitidoLargo);
  digitalWrite(led, HIGH);
  delay(pitidoLargo);
  digitalWrite(led, LOW);
  delay(pitidoLargo);
  
  
  // letra S
  digitalWrite(led, HIGH);
  delay(pitidoCorto);
  digitalWrite(led, LOW);
  delay(pitidoCorto);
  digitalWrite(led, HIGH);
  delay(pitidoCorto);
  digitalWrite(led, LOW);
  delay(pitidoCorto);
  digitalWrite(led, HIGH);
  delay(pitidoCorto);
  digitalWrite(led, LOW);
  delay(pausa); // segundo añadidos para separar comienzo y fin bucle
}

