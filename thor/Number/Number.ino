#include <EEPROM.h>


int Highscore=300;

void write_Highscore(int Highscore){
int first_digit,second_digit,third_digit,fourth_digit;
first_digit= int(Highscore/1000)%10;
second_digit= int(Highscore/100)%10;
third_digit= int(Highscore/10)%10;
fourth_digit= Highscore%10;
EEPROM.write(3,first_digit);
EEPROM.write(2,second_digit);
EEPROM.write(1,third_digit);
EEPROM.write(0,fourth_digit);
}

int read_Highscore(){
  int first_digit,second_digit,third_digit,fourth_digit;
first_digit   =EEPROM.read(3);
second_digit  =EEPROM.read(2);
third_digit   =EEPROM.read(1);
fourth_digit  =EEPROM.read(0);
  return first_digit*1000+second_digit*100+third_digit*10+fourth_digit;
}

void setup() {
  Serial.begin(9600);

// Choose read or write function.

//  Highscore=read_Highscore();         //Read highscore from arduino board, no need input  

//  write_Highscore(Highscore);         //Write Highscore to the arduino, need highscore to be integer
  
  Serial.print(Highscore);
}

void loop() {

}
