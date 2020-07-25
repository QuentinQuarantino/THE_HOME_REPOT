#define trigPin 13
#define echoPin 12
const int buzzer = 5;

void setup()
{
  // initialize GPIO 2 as an output.
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// the loop function runs over and over again forever
void loop()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(10);
  {
    if ((sensorValue >= 500) && ((distance <= 10) or (distance >=200)))
    {
      while (distance <= 10) tone(buzzer, 2000);
    }
    else
      (sensorValue < 500);
    {
      delay(1000);
    }
  }
  {
    if (distance >= 200 || distance <= 0)
    {
      Serial.println("Out of Range");
    }
    else
    {
      Serial.print(distance);
      Serial.println(" cm");
    }
    delay(500);
  }
}
