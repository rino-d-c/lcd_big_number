#include <LiquidCrystal.h>

LiquidCrystal lcd(9); // LCD pin

unsigned long previousmillis;
unsigned long currentmillis;
const long interval = 1000;
byte jam = 23;
byte menit = 59;
byte detik = 40;

byte jamPuluhan, jamSatuan, menitPuluhan, menitSatuan;

byte setting = 2;
byte up = 3;
byte set = 0;

byte bar1[8] =
{
        B11100,
        B11110,
        B11110,
        B11110,
        B11110,
        B11110,
        B11110,
        B11100
};
byte bar2[8] =
{
        B00111,
        B01111,
        B01111,
        B01111,
        B01111,
        B01111,
        B01111,
        B00111
};
byte bar3[8] =
{
        B11111,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111
};
byte bar4[8] =
{
        B11110,
        B11100,
        B00000,
        B00000,
        B00000,
        B00000,
        B11000,
        B11100
};
byte bar5[8] =
{
        B01111,
        B00111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00011,
        B00111
};
byte bar6[8] =
{
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111
};
byte bar7[8] =
{
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00111,
        B01111
};
byte bar8[8] =
{
        B11111,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
};


void setup()
{ 
  
  lcd.begin(16, 2);            
  
  lcd.createChar(1,bar1); 
  lcd.createChar(2,bar2); 
  lcd.createChar(3,bar3);
  lcd.createChar(4,bar4);
  lcd.createChar(5,bar5);
  lcd.createChar(6,bar6);
  lcd.createChar(7,bar7);
  lcd.createChar(8,bar8);


  pinMode(setting, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);

  
}

void angka_0(int col)
{ 
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(8); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void angka_1(int col)
{
  lcd.setCursor(col,0);
  lcd.write(32);                // karakter kosong
  lcd.write(32);
  lcd.write(1);
  lcd.setCursor(col,1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void angka_2(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(6);
}

void angka_3(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1); 
}

void angka_4(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32); 
  lcd.write(32);
  lcd.write(1);
}

void angka_5(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void angka_6(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void angka_7(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void angka_8(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void angka_9(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(7);  
  lcd.write(6);  
  lcd.write(1);
}

void printDigit(int value, int col) {
  if (value == 0) // angka 0
  {
    angka_0(col);
  } 
  if (value == 1) // angka 1
  {
    angka_1(col);
  } 
  if (value == 2) // angka 2
  {
    angka_2(col);
  } 
  if (value == 3) // angka 3
  {
    angka_3(col);
  } 
  if (value == 4) 
  {
    angka_4(col);
  } 
  if (value == 5) 
  {
    angka_5(col);
  } 
  if (value == 6) 
  {
    angka_6(col);
  } 
  if (value == 7) 
  {
    angka_7(col);
  } 
  if (value == 8) 
  {
    angka_8(col);
  } 
  if (value == 9) 
  {
    angka_9(col);
  }      
}  


void modeNormal()
{
    currentmillis = millis();
  if(currentmillis - previousmillis >= interval)
  {
    previousmillis = currentmillis;
    detik++;
    //lcd.clear();
  }
  if(menit < 60 && detik == 60)
  {
    detik = 0;
    menit++;
  }
  if(jam < 24 && menit == 60)
  {
    jam++;
    menit = 0;
    detik = 0;
  }
  if(jam == 24)
  {
    jam = 0;
    menit = 0;
    detik = 0;
  }
  
  jamPuluhan = jam/10;
  jamSatuan = jam%10;
  menitPuluhan = menit/10;
  menitSatuan = menit%10;
  
  printDigit(jamPuluhan, 0);  
  printDigit(jamSatuan, 3); 
  printDigit(menitPuluhan, 7);
  printDigit(menitSatuan, 10);

  lcd.setCursor(13,0);
  lcd.print(":");
  
    if(detik<10)
  {
    lcd.setCursor(14,0);
    lcd.print("0");
    lcd.print(detik);
  }
  if(detik>=10)
  {
    lcd.setCursor(14,0);
    lcd.print(detik);
  }
  
}


void modeSetMenit()
{
  lcd.setCursor(0,0);
  lcd.print("ATUR");
  lcd.setCursor(0,1);
  lcd.print("MENIT");
  menitPuluhan = menit/10;
  menitSatuan = menit%10;
  
  printDigit(menitPuluhan, 7);
  printDigit(menitSatuan, 10);
  
  if(digitalRead(up)==0)
  {
    delay(300);
    lcd.clear();
    menit++;
    if(menit == 60)
    {
      menit = 0;
    }
  }
}
void modeSetJam()
{   
  lcd.setCursor(8,0);
  lcd.print("ATUR");
  lcd.setCursor(8,1);
  lcd.print("JAM");
  lcd.setCursor(13,1);
  lcd.print(":");
  if(menit>=10)
  {
    lcd.print(menit);
  }
  else
  {
    lcd.print("0");
    lcd.print(menit);
  }
  jamPuluhan = jam/10;
  jamSatuan = jam%10;
  
  printDigit(jamPuluhan, 0);  
  printDigit(jamSatuan, 3); 
    
  if(digitalRead(up)==0)
  {
    delay(300);
    lcd.clear();
    jam++;
    if(jam == 24)
    {
      jam = 0;
    }
  }
}

void loop()
{
  if(set==0)
    modeNormal();
    
  if(set==1)
    modeSetMenit();
  
  if(set==2)
    modeSetJam();
  
  if(digitalRead(setting)==0)
  {
    delay(300);
    lcd.clear();
    set++;
    if(set>=3)
    set=0;
  }
  lcd.setCursor(6,0);
  lcd.print("*");
  lcd.setCursor(6,1);
  lcd.print("*");
}

