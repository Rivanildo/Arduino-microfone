//Programa: Sensor de som KY-038
//Autor: Arduino e Cia

//Definicao pinos leds
int pinoled_ver = 3;
int pinoled_ama = 4;
int pinoled_verm = 5;
int pinoled_azul = 6;
int pinoled_bra = 2;

//Definicao pinos sensor
int pino_analogico = A5;
int pino_digital = 7;

int valor_A0 = 0;
int valor_D = 0;

void setup()
{
  Serial.begin(9600);
  //Define pinos led como saida
  pinMode(pinoled_ver, OUTPUT);
  pinMode(pinoled_ama, OUTPUT);
  pinMode(pinoled_verm, OUTPUT);
  pinMode(pinoled_azul, OUTPUT);
  pinMode(pinoled_bra, OUTPUT);
  //Define pinos sensor como entrada
  pinMode(pino_analogico, INPUT);
  pinMode(pino_digital, INPUT);
}

void loop()
{
  valor_A0 = analogRead(pino_analogico);
  valor_D = digitalRead(pino_digital);
  Serial.print("Saida A0: ");
  Serial.print(valor_A0);
  Serial.print(" Saida D0: ");
  Serial.println(valor_D);
  //Intensidade baixa
  if (valor_A0 <= 304)
  {
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, LOW);
    digitalWrite(pinoled_verm, LOW);
    digitalWrite(pinoled_azul, LOW);
    digitalWrite(pinoled_bra, LOW);
  }
  //Intensidade media
  if (valor_A0 >=305){
   digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, HIGH);
    digitalWrite(pinoled_verm, LOW);
    digitalWrite(pinoled_azul, LOW);
    digitalWrite(pinoled_bra, LOW);
  }
  //Intensidade alta
  if (valor_A0 >= 307){
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, HIGH);
    digitalWrite(pinoled_verm, HIGH);
    digitalWrite(pinoled_azul, LOW);
    digitalWrite(pinoled_bra, LOW);
  }
  if(valor_A0 >= 311){
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, HIGH);
    digitalWrite(pinoled_verm, HIGH);
    digitalWrite(pinoled_azul, HIGH);
    digitalWrite(pinoled_bra, LOW);
  }
  if(valor_A0 >315){
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, HIGH);
    digitalWrite(pinoled_verm, HIGH);
    digitalWrite(pinoled_azul, HIGH);
    digitalWrite(pinoled_bra, HIGH);
  }
  delay(50);
  //Apaga todos os leds
  digitalWrite(pinoled_ver, LOW);
  digitalWrite(pinoled_ama, LOW);
  digitalWrite(pinoled_verm, LOW);
  digitalWrite(pinoled_azul, LOW);
  digitalWrite(pinoled_bra, LOW);
}
