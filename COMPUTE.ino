const int AdditionPin = 13;
const int SubtractionPin = 12;
const int MultiplicationPin = 11;
const int DivisionPin = 10;
const int EqualPin = 9;
const int CountPin = 8;
const int CancelPin = 7;
const int DecidePin = 6;
int sum=0;
int symble_type=0;
int past_temp=0;
int temp=0;
int IfAnyPin=0;//判斷當下按鍵狀態
String show="";//運算式

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(AdditionPin, INPUT);     
  pinMode(SubtractionPin, INPUT);     
  pinMode(MultiplicationPin, INPUT);
  pinMode(DivisionPin, INPUT);
  pinMode(EqualPin, INPUT);
  pinMode(CountPin, INPUT);     
  pinMode(CancelPin, INPUT);
  pinMode(DecidePin, INPUT);
    Serial.println(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  count();   // Serial.println("Round");
  symble();
}

//void compute(

void symble(){
  while(1){
    if( digitalRead(13)==HIGH){
      if(IfAnyPin==0){
        show+='+';
        symble_type=1;
        Serial.println("+");
        Serial.print("目前已輸入的運算式為：");
        Serial.println(show);                
        Serial.println("0");
        IfAnyPin=1;
        delay(100);
        break;
      }
    }/*else if(digitalRead(12)==HIGH){
      
    }else if(digitalRead(11)==HIGH){
      
    }else if(digitalRead(10)==HIGH){

    }else if(digitalRead(9)==HIGH){
      
    }*/else{
      IfAnyPin=0;
      delay(100);
    }
  }
}

void count(){
  while(1){
    if(digitalRead(CountPin)==HIGH){
      if(IfAnyPin==0){
        temp+=1;
        Serial.println(temp);
        IfAnyPin=1;
        delay(100);
      }
    }else{
      IfAnyPin=0;
      delay(100);
    }

    if(digitalRead(DecidePin)==HIGH){
      if(IfAnyPin==0){
        if(temp!=0){
          past_temp=temp;
          temp=0;
          show+=past_temp;
          Serial.print("輸入的數字為：");
          Serial.println(show);
          Serial.print("繼續輸入運算符號：");
          //Serial.println(temp);
          IfAnyPin=1;
          delay(100);
          break;
        }
      }
    }else{
      IfAnyPin=0;
      delay(100);
    }
  }
}

