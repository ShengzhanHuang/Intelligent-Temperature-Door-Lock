#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
 wiringPiSetup() ;
  pinMode(7, INPUT);
  digitalWrite(7, HIGH);
}
 // {
  //  digitalWrite(0, HIGH) ; delay (500) ;
   // digitalWrite(0,  LOW) ; delay (500) ;
 // }
//}


//void setup(){

  //wiringPiSetup();
  //pinMode(13, INPUT);
  //digitalWrite(13, HIGH);
//}

void loop(){

  if(digitalRead(7) == LOW){
    system("raspistill -o imag%01d.jpg");
  }
 // else{
  //  printf("close");
  //}
}
