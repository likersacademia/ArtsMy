

#include <Servo.h>
#define motorPin 3
Servo myservo;



void setup() {


/////////サーボモーター////////
  
myservo.attach(motorPin,700,2300);

/////////////////////////////


}

void loop() {

/////////サーボモーター////////
//delay（　　）の中の数字を変更して、何秒間そのモーターを回転をさせるか考えてみよう
//1000で1秒です。


 
  
  myservo.write(1500);        //2秒間止まる
  delay(2000);
  



//////追加することもできます////


/////////////////////////////
  
}
