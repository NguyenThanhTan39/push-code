const int ADC_PIN = A0;
const float Vref = 5.0;
const int INTERVAL = 50;
unsigned long preMillis = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ADC_PIN, INPUT);
}

void loop() {
  unsigned long curMillis = millis();
  if (curMillis - preMillis >= INTERVAL)
  {
    preMillis = curMillis;
    int raw = analogRead(ADC_PIN);
    float voltage = raw * Vref/1023.0;
    Serial.println(voltage);
  }
}
