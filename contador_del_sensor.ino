// sensor inflarrojo


int infrarrojo = 11;
int valor = 0;
int led = 10;

int contador = 0;
int estadoAnterior = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(infrarrojo, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // 1. PRIMERO LEES EL SENSOR
  valor = digitalRead(infrarrojo);
  
  // 2. PREGUNTAS SI ACABA DE ENTRAR LA MANO Y SUMAS
  if (valor == LOW && estadoAnterior == HIGH) {
    contador++;
    digitalWrite(led, HIGH);
    Serial.println(contador);
  } 
  else if (valor == HIGH) {
    // Si ya no hay mano, apagas el LED
    digitalWrite(led, LOW);
  }

  // 3. HASTA EL FINAL GUARDAS LA FOTO DEL PASADO
  estadoAnterior = valor;
  
  delay(200); 
}
