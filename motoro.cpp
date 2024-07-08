const int digital_pin_right = 5;
const int digital_pin_mid = 19;
const int digital_pin_left = 18;

const int in3 = 32;
const int in4 = 35;
const int enb = 33;
const int in1 = 26;
const int in2 = 25;
const int ena = 27;
const int maxSpeed = 180; // Adjust speed here (0-255 range)
const int minSpeed = 90; // Adjust speed here (0-255 range)
const int midSpeed = 120; // Adjust speed here (0-255 range)

void setup() {
  Serial.begin(9600);
  pinMode(digital_pin_right, INPUT);
  pinMode(digital_pin_mid, INPUT);
  pinMode(digital_pin_left, INPUT);
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void foward(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ena, maxSpeed);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enb, maxSpeed);
}

void left(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ena, midSpeed);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enb, minSpeed);
}

void right(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ena, ;);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enb, midSpeed); 
}


void stopCar(){

    analogWrite(ena, 0);
    analogWrite(enb, 0);
}

void loop() {
  int sensor_right = digitalRead(digital_pin_right);
  int sensor_mid  = digitalRead(digital_pin_mid);
  int sensor_left  = digitalRead(digital_pin_left);

//   if(sensor_left == LOW && sensor_mid == HIGH && sensor_right == LOW)
//  {
//      foward();
//     
//  } else {
//    stopCar();
//  }

  if (sensor_left == HIGH && sensor_mid == HIGH && sensor_right == LOW)
  {
      left();
      Serial.println("Esquerda");
  }   
  else if (sensor_left == HIGH && sensor_mid == LOW && sensor_right == LOW)
  {
      left();
      Serial.println("Esquerda");
  }   
  else if(sensor_left == LOW && sensor_mid == HIGH && sensor_right == HIGH)
  {
      right();
      Serial.println("Direita");
  }   
  else if(sensor_left == LOW && sensor_mid == HIGH && sensor_right == LOW)
  {
      foward();
      Serial.println("Frente");
  }    
  else if(sensor_left == LOW && sensor_mid == LOW && sensor_right == HIGH)
  {
      right();
      Serial.println("Direita");
  }
  else 
  {
      stopCar();
      Serial.println("Parar");
  }
}