# Arduino計算機
## 摘要
Arduino製作計算機，使用8個開關分別控制加、減、乘、除、等於、計數、取消等動作<br>
並使用Serial Library將Arduino與外埠電腦（PC端）進行序列通訊 (Serial Communication) <br>
Project使用通訊速率9600bps 將按鍵所輸入的訊息傳輸至PC端，並進行運算，將運算結果輸出於PC端的Serial Monitor<br>

## 使用說明
將Project中的COMPUTE.ino燒錄至Arduino UNO中，
並且將各PIN腳位接至各個button(腳位說明請見下方)。<br>

## 腳位(pin)說明
Arduino數位輸入PIN說明如下：
* PIN 13 ：AdditionPin（加號鍵）
* PIN 12 ：SubtractionPin（減號鍵）
* PIN 11 ：MultiplicationPin（乘號鍵）
* PIN 10 ：DivisionPin（除號鍵）
* PIN 9  ：EqualPin（等於鍵）
* PIN 8  ：CountPin（計數鍵）
* PIN 7  ：CancelPin（取消鍵）
* PIN 6  ：DecidePin（決定鍵）<br>

## 注意
* 請將所有腳位均接上輸入按鈕，否則該腳位會一直收到高電壓的訊息，造成Serial傳輸錯誤
