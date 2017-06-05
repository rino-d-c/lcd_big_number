#include <LiquidCrystal.h>

LiquidCrystal lcd(5,6,7,8,9,10); // LCD pin


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
  lcd.begin(16, 2);              // inisialisasi kolom dan baris LCD    
  lcd.createChar(1,bar1); // membuat karakter bar1
  lcd.createChar(2,bar2); 
  lcd.createChar(3,bar3);
  lcd.createChar(4,bar4);
  lcd.createChar(5,bar5);
  lcd.createChar(6,bar6);
  lcd.createChar(7,bar7);
  lcd.createChar(8,bar8);
  
  
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

void printNomor(int nomor) // cetak nomor
{
  int ribuan, ratusan, puluhan, satuan;
  if(nomor >= 1000)
  {
    ribuan = (nomor - (nomor % 1000)) / 1000;
    nomor = nomor % 1000;
  }
  else
  {
    ribuan = 0;
  }
  if(nomor >= 100)
  {
    ratusan = (nomor - (nomor % 100)) / 100;
    nomor = nomor % 100;
  }
  else
  {
    ratusan = 0;
  }
  if(nomor >= 10) 
  {
    puluhan = (nomor - (nomor % 10)) / 10;
    nomor = nomor % 10;
  }
  else
  {
    puluhan = 0;
  }
  satuan = nomor;

  printDigit(ribuan, 1);   // cetak digit ribuan, mulai di kolom 1
  printDigit(ratusan, 5);  // cetak digit ratusn, mulai di kolom 5
  printDigit(puluhan, 9);  // cetak digit puluhan, mulai di kolom 9
  printDigit(satuan, 13);  // cetak digit satuan, mulai di kolom 13
}

void loop()
{
    printNomor(3471);   // cetak nomor 3471
}

