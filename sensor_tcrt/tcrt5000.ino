const int digital_pin_right = 34;
const int digital_pin_left = 35;

void setup() {
  Serial.begin(9600);
  pinMode(digital_pin_right, INPUT);
  pinMode(digital_pin_left, INPUT);
}

void loop() {
  int sensor_right = digitalRead(digital_pin_right);
  int sensor_left  = digitalRead(digital_pin_left);
  delay(100);
  if (sensor_right == LOW && sensor_left == LOW)
  {
    Serial.print("Siga em frente\n");
  }
  else if (sensor_right == HIGH && sensor_left == HIGH)
  {
    Serial.print("Pare\n");
  }
  else if (sensor_right == HIGH && sensor_left == LOW )
  {
    Serial.print("Vire para a direita\n");
  }
  else if (sensor_right == LOW && sensor_left == HIGH )
  {
    Serial.print("Vire para a esquerda\n");
  }
}
