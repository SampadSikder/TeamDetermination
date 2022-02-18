// C++ code
//
#include <Servo.h>

int censor_val = 0;

int outputValue = 0;

int gasValue = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);

  pinMode(A1, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  outputValue = 0;
  servo_9.write(outputValue);
  gasValue = analogRead(A1);
  if (gasValue >= 300) {
    outputValue += 180;
    servo_9.write(outputValue);
    digitalWrite(13, HIGH);
    Serial.print("Smoke detected");
    Serial.print(gasValue);
    Serial.println("");
    delay(86400000); 
  } else {
    digitalWrite(13, LOW);
    Serial.println(gasValue);
  }
  
}
