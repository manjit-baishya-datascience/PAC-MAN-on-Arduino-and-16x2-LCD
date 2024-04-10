#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or whatever your I2C address is
#define I2C_ADDR 0x27

// Set the LCD dimensions (16 columns and 2 rows)
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Initialize the LCD object
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

const int Btn_1 = 2;
const int Btn_2 = 4;
const int Btn_3 = 7;
const int Btn_4 = 8;

int counter = 0;
int match = -1;
int score = 0;

int X = 0;
int Y = 0;

int prev_X = 0;
int prev_Y = 0;

int monster_X = 0;
int monster_Y = 0;

int monster_prev_X = 0;
int monster_prev_Y = 0;

// Define custom character bitmap for a single dot
byte block[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte monster[8] = {
  B00100,
  B01110,
  B11111,
  B10101,
  B11111,
  B11011,
  B00000,
  B11111
};

void setup() {

  pinMode(Btn_1, INPUT);
  pinMode(Btn_2, INPUT);
  pinMode(Btn_3, INPUT);
  pinMode(Btn_4, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(12, 0);
  lcd.print("|Tot");

  lcd.setCursor(12, 1);
  lcd.write('|');

  lcd.setCursor(13, 1);
  lcd.print(score);

  randomSeed(analogRead(0));
}

void loop() {
  int Btn_1_state = digitalRead(Btn_1);
  int Btn_2_state = digitalRead(Btn_2);
  int Btn_3_state = digitalRead(Btn_3);
  int Btn_4_state = digitalRead(Btn_4);

  if(X == monster_X && Y == monster_Y){
    match = 1;
    score++;
  }

  lcd.setCursor(13, 1);
  lcd.print(score);

  // counter
  if(counter == 0 || match == 1){
    match = 0;
    counter = 20;

    monster_prev_X = monster_X;
    monster_prev_Y = monster_Y;
    lcd.setCursor(monster_prev_X, monster_prev_Y);
    lcd.write(' ');

    monster_X = random(0, 12);
    monster_Y = random(0, 2);
    lcd.createChar(0, monster);
    lcd.setCursor(monster_X, monster_Y);
    lcd.write(byte(0)); 
  }

  counter--;

  if(Btn_1_state == HIGH) {
    lcd.setCursor(X, Y);
    lcd.write(' ');
    
    if(X > 0 && X <= 11){
      X--;
      blinkCursor(X,Y);
    }

    else if(X == 0 && Y == 0){
      X = 11;
      Y = 1;
      blinkCursor(X,Y);
    }

    else if(X == 0 && Y == 1){
      X = 11;
      Y = 0;
      blinkCursor(X,Y);
    }
  }

  else if(Btn_2_state == HIGH) {
    lcd.setCursor(X, Y);
    lcd.write(' ');

    if(X >= 0 && X < 11){
      X++;
      blinkCursor(X,Y);
    }

    else if(X == 11 && Y == 0){
      X = 0;
      Y = 1;
      blinkCursor(X,Y);
    }

    else if(X == 11 && Y == 1){
      X = 0;
      Y = 0;
      blinkCursor(X,Y);
    }
  }

  else if(Btn_3_state == HIGH) {
    lcd.setCursor(X, Y);
    lcd.write(' ');

    if(Y == 0){
      Y = 1;
      blinkCursor(X,Y);
    }

    else if(Y == 1){
      Y = 0;
      blinkCursor(X,Y);
    }
  }

  else if(Btn_4_state == HIGH) {
    lcd.setCursor(X, Y);
    lcd.write(' ');

    X = 0;
    Y = 0;
    blinkCursor(X,Y);
  }

  else{
    lcd.setCursor(X, Y);
    lcd.write(' ');
    blinkCursor(X,Y);
  }
  delay(100);
}

void blinkCursor(int X_cor, int Y_cor){
  int X = X_cor;
  int Y = Y_cor;
  lcd.createChar(1, block);
  lcd.setCursor(X, Y);
  lcd.write(byte(1));
}