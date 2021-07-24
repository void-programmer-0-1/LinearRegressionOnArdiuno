#include "vectors.h"
#include "LinearRegression.h"


int LED0 = 2;
int LED1 = 3;
int LED2 = 4;
int LED3 = 5;
int LED4 = 6;
int LED5 = 7;
int LED6 = 8;
int LED7 = 9;
int LED8 = 10;
int LED9 = 11;

int LEDS[10] = {2,3,4,5,6,7,8,9,10,11};

int number = 0;

float coeff[2] = {2.00067,0.147418};

void setup() 
{
  Serial.begin(9600);
  pinMode(LED0,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);
  pinMode(LED9,OUTPUT); 
}

void loop() 
{
  
  if (Serial.available() > 0) 
  {
    number = Serial.parseInt();
    Serial.println(number);
    if(number > 0)
    { 
      char pred[11];
      
      float prediction = predict(coeff,number);
      int prediction_int = (int)prediction;

      dtostrf(prediction,-10,2,pred);
      
      Serial.println("Prediction");
      Serial.println(prediction);

  
      for(int i=0;i<10;i++)
      { 
        if(pred[i] != ' ')
        {
          if(pred[i] == '.') break;
          Serial.println(pred[i]);
          int index = pred[i] - '0';
          Serial.println(index);
          Serial.println(LEDS[index]);
          digitalWrite(LEDS[index],HIGH);
          delay(3000);
          digitalWrite(LEDS[index],LOW);
          
        }
      }
      
    }
  }
}
