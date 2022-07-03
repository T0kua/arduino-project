#define PIN_TRIG 12
#define PIN_ECHO 11

long duration, cm,cm1;
/*
 * trig 12 port
 * echo 11 port
 * port 5 output
 */
void setup() {

  // Инициализируем взаимодействие по последовательному порту
  //Определяем вводы и выводы
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(5, OUTPUT);


  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG,LOW);

  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
  digitalWrite(PIN_TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);


  cm1 = (duration / 2) / 29.1;
}

void loop() {

  // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.

  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG,LOW);

  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
  digitalWrite(PIN_TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);


  cm = (duration / 2) / 29.1;
  if(cm1 < cm){
    digitalWrite(5,LOW);
  }
  if (cm1 > cm + 10){
    digitalWrite(5,HIGH);
    Serial.println("warn");
  }
  Serial.print("Расстояние до объекта: ");
  Serial.print(cm);
  Serial.println(" см.  ");
  // Задержка между измерениями для корректной работы скеча
  delay(250);
}
