#define trigPin 13
#define echoPin 12
int buzzer = 7;

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
      if (((distance <= 10) or (distance > 200)) && (sensorValue <=150))
        {
          digitalWrite(buzzer, HIGH);
        }
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
}    
      
