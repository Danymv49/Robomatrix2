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
int acelerador = 255;
int lados = 90;
int atras = 150;

// Subfunciones
void alto();
void derecha();
void izquierda();
void avanza();
void retrocede();
void setup()
{
  // Configuración de entradas y salidas
  pinMode(motorderdir, OUTPUT);
  pinMode(motorizqdir, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  alto();
  delay(100);
}

void loop() 
{
  pinMode(motorderdir, OUTPUT);
  pinMode(motorizqdir, OUTPUT);
  proxizq = digitalRead(4);
  proxcen = digitalRead(5);
  proxder = digitalRead(6);
  

  // Condición principal
  if (proxizq == HIGH && proxcen == HIGH && proxder == HIGH) 
  {
    avanza();
    delay(50); 
  } 
        else 
    {
         //if(proxder== LOW && proxcen== LOW && proxizq==LOW){
            //retrocede();
            //delay(10);
          //}
        if (proxizq == LOW && proxcen == LOW) 
        { 
            derecha();
            delay(40);
        }
          else 
    {
          if (proxizq == LOW) 
        {
          derecha();
          delay(40);
        }
          else
    { 
          if (proxder == LOW) 
        {
              izquierda();
              delay(40);
        } 
          else
          if (proxcen == LOW) 
        {
              izquierda();
              delay(40);
              derecha();
              delay(100);
        }
              else
     {
          if (proxcen == LOW && proxder == LOW && proxizq == LOW) 
        {
              izquierda();
              delay(40);
              derecha();
              delay(100);
         }
    }
    }
    }
}


  contactoizq = digitalRead(2);
  contactoder = digitalRead(3);
  delay(10);
      if(contactoizq == LOW)
      {
        retrocede();
        delay(50); 
        derecha();
        delay(10);
      }
      if (contactoder == LOW)
      {
        retrocede();
        delay(50);
        izquierda();
        delay(200);
      } 
      if(contactoizq == LOW && contactoder == LOW)
      {
        retrocede();
        delay(50);
        derecha();
        delay(200);
      }
}

void alto()
 {
  analogWrite(motordervel, 0);
  analogWrite(motorizqvel, 0);
 }
void derecha()
 {
  analogWrite(motordervel, lados);
  analogWrite(motorizqvel, lados);
  digitalWrite(motorderdir, LOW);
  digitalWrite(motorizqdir, HIGH);
 }
void izquierda() 
 {
  analogWrite(motordervel, lados);
  analogWrite(motorizqvel, lados);
  digitalWrite(motorderdir, HIGH);
  digitalWrite(motorizqdir, LOW);
 }
void avanza() 
 {
  analogWrite(motordervel, acelerador);
  analogWrite(motorizqvel, acelerador);
  digitalWrite(motorderdir, HIGH);
  digitalWrite(motorizqdir, HIGH);
 }
void retrocede() 
 {
  analogWrite(motordervel, atras);
  analogWrite(motorizqvel, atras);
  digitalWrite(motorderdir, LOW);
  digitalWrite(motorizqdir, LOW);
 }
 
