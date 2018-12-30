

/////////サーボモーター////////

#include <Servo.h>
#define motorPin 3
Servo myservo;

/////////////////////////////



/////////距離センサー//////////

#define echoPin 4
#define trigPin 5 
double Duration = 0; //受信した間隔
double Distance = 0; //距離

/////////////////////////////




void setup() {


/////////サーボモーター////////
  
  myservo.attach(motorPin,700,2300);

/////////////////////////////



/////////距離センサー//////////
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);

/////////////////////////////
  

}



void loop() {



/////////距離センサー//////////
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //超音波を出力
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH); //センサからの入力
  if (Duration > 0) {
  Duration = Duration/2; //往復距離を半分
  Distance = Duration*340*100/1000000; //音速を340m/sに設定 
  Serial.print("Distance:");
  Serial.print(Distance);
  Serial.println("cm");
/////////////////////////////


  }



////////////距離を感知してモーターの動きをかえる/////////////////

//if (Distance < 20){　　　　}と書いてある「<」「20」に変更することができます
//これは、20センチ以下だと、その｛　　　｝の中の反応が起こります。
//それ以外のときにどんな動きをさせるかは、else｛　　｝の中に書きます。
//今回は、myservo.write(1500);と書いてるので、20センチ以内ではないときは、止まるようになっています。

///////////////////////////////////////////////////////////



if (Distance < 20) {


  myservo.write(1400);  


 
 
  }

  
  else {


  myservo.write(1500);
 


 }

}
