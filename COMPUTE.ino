const int AdditionPin = 13;
const int SubtractionPin = 12;
const int MultiplicationPin = 11;
const int DivisionPin = 10;
const int EqualPin = 9;
const int CountPin = 8;
const int CancelPin = 7;
const int DecidePin = 6;
int sum=0;
int IfAnyPin=0;//判斷當下按鍵狀態

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
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8)==HIGH){
    if(IfAnyPin==0){
      sum+=1;
      Serial.println(sum);
      IfAnyPin=1;
      delay(50);
    }
  }else{
    IfAnyPin=0;
    delay(50);
  }
}
