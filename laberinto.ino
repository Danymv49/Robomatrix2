//distancia 
int distancia; 

// Definir pines de los motores
int motordervel = 10;
int motorderdir = 12;
int motorizqvel = 11;
int motorizqdir = 13;

//contacto 
int contactoizq; 
int contactoder;

// Sensores infrarrojos
int proxizq;
int proxcen;
int proxder;

// Velocidad
int acelerador = 125;
int aceleradorlados = 80; 
int atras = 100;

// Subfunciones
void alto();
void derecha();
void izquierda();
void avanza();
void retrocede();

void setup() {
  // Configuración de entradas y salidas
  Serial.begin(115200);
  pinMode(motorderdir, OUTPUT);
  pinMode(motorizqdir, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  alto();
  delay(100);
}

void loop() {
  pinMode(motorderdir, OUTPUT);
  pinMode(motorizqdir, OUTPUT);
  proxizq = digitalRead(4);
  proxcen = digitalRead(5);
  proxder = digitalRead(6);

  // Condición principal
  if( proxcen == LOW){
    avanza(); 
    delay(100);
  }else{
    retrocede();
  }if (proxizq == HIGH){
    derecha();
    delay(100);
  }else {
    if (proxder == HIGH){
      izquierda();
      delay(100);
    }
  }

contactoizq = digitalRead(2);
contactoder = digitalRead(3);
delay(500);
if(contactoizq == LOW){
  retrocede();
  delay(100); 
  derecha();
  delay(100);
}
if (contactoder == LOW){
  retrocede();
  delay(100);
  izquierda();
  delay(100);
} 
if(contactoizq == LOW && contactoder == LOW){
  retrocede();
  delay(100);
  derecha();
  delay(100);
}

}
void alto() {
  analogWrite(motordervel, 0);
  analogWrite(motorizqvel, 0);
}

void derecha() {
  analogWrite(motordervel, aceleradorlados);
  analogWrite(motorizqvel, aceleradorlados);
  digitalWrite(motorderdir, LOW);
  digitalWrite(motorizqdir, HIGH);
}

void izquierda() {
  analogWrite(motordervel, aceleradorlados);
  analogWrite(motorizqvel, aceleradorlados);
  digitalWrite(motorderdir, HIGH);
  digitalWrite(motorizqdir, LOW);
}

void avanza() {
  analogWrite(motordervel, acelerador);
  analogWrite(motorizqvel, acelerador);
  digitalWrite(motorderdir, HIGH);
  digitalWrite(motorizqdir, HIGH);
}

void retrocede() {
  analogWrite(motordervel, atras);
  analogWrite(motorizqvel, atras);
  digitalWrite(motorderdir, LOW);
  digitalWrite(motorizqdir, LOW);
}
