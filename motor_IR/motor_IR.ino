/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(115200);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 687050){
      digitalWrite(6, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(10, LOW);
      
      Serial.print('S');
      delay(100);
    }
      if (results.value == 752586){
      digitalWrite(5, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(11, LOW);
     
      
      Serial.print('S');
      delay(100);
    }

       if (results.value == 40000){
      digitalWrite(5, LOW);
      digitalWrite(10, LOW);
      digitalWrite(6, LOW);
      digitalWrite(11, LOW);
       }

         if (results.value == 822218){
      digitalWrite(5, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(6, LOW);
      digitalWrite(11, LOW);
       }

       if (results.value == 891850){
      digitalWrite(5, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(11, LOW);
       }
    //Serial.println(results.value);
    //Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
