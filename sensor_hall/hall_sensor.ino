const int hall_sensor_pin = 32;
const int internal_led = 2;

volatile unsigned long last_time = 0;
volatile unsigned long current_time = 0;
volatile bool sensor_triggered = false;

const float roda = 0.204; // perímetro da roda

void setup() {
  Serial.begin(9600);
  
  pinMode(hall_sensor_pin, INPUT);
  pinMode(internal_led, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(hall_sensor_pin), sensorInterrupt, FALLING);
}

void loop() {
  if (sensor_triggered)
  {
    unsigned long interval = current_time - last_time;
    last_time = current_time;

    float rpm = (60.0 * 1000.0) / interval;
    float velocidade = (rpm * roda) / 60.0;

    Serial.print("RPM: ");
    Serial.println(rpm);
    
    Serial.print("Velocidade: ");
    Serial.println(velocidade);

    sensor_triggered = false;
  }
//  Serial.print("Leitura analógica=");
//  Serial.println(digitalRead(hall_sensor_pin));
//  delay(1000); 
}

void sensorInterrupt()
{
  current_time = millis();
  sensor_triggered = true;
}
