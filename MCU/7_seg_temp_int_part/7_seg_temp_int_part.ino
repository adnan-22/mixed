byte lupTable[17]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x80}; 
byte index[2];
void setup() {
  Serial.begin(9600);
  DDRD=0xFF;
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  analogReference(INTERNAL); 
  int roomTemp=100*(1.1/1024)*analogRead(A0);
  int y=roomTemp;
  Serial.println(roomTemp);
  for(int i=0;i<2;i++)
  {
    index[i]=y%10;
    y=y/10;
  }
    //Serial.println(lupTable[index[1]],HEX);
    //Serial.println(lupTable[index[0]],HEX);
}
void loop() {
  PORTD=lupTable[index[1]]; //cc code of dp0
  digitalWrite(8,LOW);   //cc0
  digitalWrite(9,HIGH); //cc1
  delay(10);
  PORTD=lupTable[index[0]];//cc code of dp1
  digitalWrite(8,HIGH);  //cc0
  digitalWrite(9,LOW);   //cc1
  delay(10);
}
