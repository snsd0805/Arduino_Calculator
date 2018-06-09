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
  process();
  //once_analysis();
}

void process(){
  while(1){
    count();
    symble();
  }
}

void symble(){
  while(1){
    reset();
    if( digitalRead(AdditionPin)==HIGH){
      if(IfAnyPin==0){
        show+="+";
        symble_type=1;
        Serial.println("+");
        Serial.print("目前已輸入的運算式為：");
        Serial.println(show);                
        Serial.println("0");
        IfAnyPin=1;
        delay(100);
        break;
      }
    }else if(digitalRead(SubtractionPin)==HIGH){
      if(IfAnyPin==0){
        show+="-";
        Serial.println("-");
        Serial.print("目前已輸入的運算式為：");
        Serial.println(show);                
        Serial.println("0");
        IfAnyPin=1;
        delay(100);
        break;
      }
    }else if(digitalRead(MultiplicationPin)==HIGH){
      if(IfAnyPin==0){
        show+="*";
        Serial.println('*');
        Serial.print("目前已輸入的運算式為：");
        Serial.println(show);                
        Serial.println("0");
        IfAnyPin=1;
        delay(100);
        break;
      }
    }else if(digitalRead(DivisionPin)==HIGH){
        if(IfAnyPin==0){
        show+="/";
        Serial.println("/");
        Serial.print("目前已輸入的運算式為：");
        Serial.println(show);                
        Serial.println("0");
        IfAnyPin=1;
        delay(100);
        break;
      }
    }else if(digitalRead(EqualPin)==HIGH){
      if(IfAnyPin==0){
        
        Serial.print("答案：");
          once_analysis();
        IfAnyPin=1;
        delay(100);
        break;
      }
    }else{
      IfAnyPin=0;
      delay(100);
    }
  }

}

void reset(){
  if( digitalRead(CancelPin)==HIGH){
      if(IfAnyPin==0){
        sum=0;
        symble_type=0;
        past_temp=0;
        temp=0;
        show="";
        Serial.println("取消");
        Serial.println("0");
        IfAnyPin=1;
        delay(100);
        IfAnyPin=0;
        process();
      }
    }else{
      IfAnyPin=0;
      delay(100);
    }
}
void count(){
  while(1){
    reset();
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
    }else{
      IfAnyPin=0;
      delay(100);
    }
  }
}


void once_analysis(){
        //Serial.println("原始："+show);

  int a=0;
  int b=0;
  int center;
  int len=show.length();
              //Serial.println("長度");
              //Serial.println(len);

  for(int i=0;i<len;i++){
   if(show.charAt(i)=='*' || show.charAt(i)=='/'){
            //Serial.println("找到");

    int Min;
    int Max;
    center=i;
    int times=1;
    for(int j=center-1;j>=0;j--){
      if(show.charAt(j)>='0' && show.charAt(j)<='9'){
        a+=times*((int)show.charAt(j)-48);
        times*=10;
        if(j==0){
          Min=0;
        }
      }else{
        Min=j+1;
        times=10;
        break;
      }
    }
    for(int j=center+1;j<=len;j++){
                  //Serial.print("找max");
                  //Serial.println(show.charAt(j));

      if(show.charAt(j)>='0' && show.charAt(j)<='9'){
        b=b*times+((int)show.charAt(j)-48);
        //Serial.print("b:");
        //Serial.println(b);
        if(j==len){
          Max=len;
        }
      }else{
        Max=j-1;
        times=1;
        break;
      }
    }
            //Serial.println("最小：");
            //Serial.println(Min);
            //Serial.println("center：");
            //Serial.println(center);
            //Serial.println("最大：");
            //Serial.println(Max);
//Serial.print("a：");
                //Serial.println(a);Serial.print("b：");
                //Serial.println(b);

    int sum;
    if(show.charAt(i)=='*'){
      sum=a*b;
    }else{
      sum=a/b;
    }
    a=0;b=0;

                //Serial.print("總和：");
                //Serial.println(sum);

    //Serial.println(sum);
    String sumstring;
     sumstring+=sum;
                //Serial.print("sumstring：");
                //Serial.println(sumstring);
    String replaced="";
    for(int j=Min;j<=Max;j++){
          replaced+=show.charAt(j);
    }
    show.replace(replaced,sumstring);
                       //Serial.print("temp");
                       //Serial.println(show);

   }
  
  }
  if(show.indexOf("*")!=-1 || show.indexOf('/')!=-1){
       once_analysis();
  }
                   Serial.println(show);
      //Serial.println(show);
Serial.println("按取消鍵重新計算");
}


