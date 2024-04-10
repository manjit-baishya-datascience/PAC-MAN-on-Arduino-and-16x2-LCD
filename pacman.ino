// importing required libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// setting LCD address to 0x27
#define I2C_ADDR 0x27

// setting the LCD dimensions (16 columns and 2 rows)
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// initializing the LCD object
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

// defining input pins for input
const int Btn_1 = 2;
const int Btn_2 = 4;
const int Btn_3 = 7;
const int Btn_4 = 8;

// defining variables to store data throughout the game
int counter = 0;
int match = 0;
int score = -1;

// current position of snake
int X = 0;
int Y = 0;

// previous position of snake
int prev_X = 0;
int prev_Y = 0;

// current position of monster
int monster_X = 0;
int monster_Y = 0;

// previous position of monster
int monster_prev_X = 0;
int monster_prev_Y = 0;

// defining custom character bitmap for snake
byte snake[8] = {
  B11111,
  B01110,
  B01110,
  B00100,
  B00100,
  B01110,
  B01110,
  B11111
};

// defining custom character bitmap for monster
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

// setting up the main program
void setup() {

  // defining the pinmodes for all input and pins
  pinMode(Btn_1, INPUT);
  pinMode(Btn_2, INPUT);
  pinMode(Btn_3, INPUT);
  pinMode(Btn_4, INPUT);

  // initializing the LCD
  lcd.init();
  lcd.backlight();

  // printing message and score
  lcd.setCursor(12, 0);
  lcd.print("|Tot");
  lcd.setCursor(12, 1);
  lcd.write('|');

  // randomizing the value
  randomSeed(analogRead(0));
}

// defining the loop sequence
void loop() {

  // reading input pins
  int Btn_1_state = digitalRead(Btn_1);
  int Btn_2_state = digitalRead(Btn_2);
  int Btn_3_state = digitalRead(Btn_3);
  int Btn_4_state = digitalRead(Btn_4);

  // setting conditions for positioning snake
  if(X == monster_X && Y == monster_Y){
    match = 1;
    score++;
  }

  // update score
  lcd.setCursor(13, 1);
  lcd.print(score);

  // randomly placing snake
  if(counter == 0 || match == 1){
    match = 0;
    counter = 20;

    // clearing previous position of snake
    monster_prev_X = monster_X;
    monster_prev_Y = monster_Y;
    lcd.setCursor(monster_prev_X, monster_prev_Y);
    lcd.write(' ');

    // printing new position of snake
    monster_X = random(0, 12);
    monster_Y = random(0, 2);
    lcd.createChar(0, monster);
    lcd.setCursor(monster_X, monster_Y);
    lcd.write(byte(0)); 
  }

  // decrementing counter
  counter--;

  // on pressing button 1 -> go left
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

  // on pressing button 2 -> go right
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

  // on pressing button 3 -> go up or down
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

  // on pressing button 4 -> reset snake to (0,0)
  else if(Btn_4_state == HIGH) {
    lcd.setCursor(X, Y);
    lcd.write(' ');

    X = 0;
    Y = 0;
    blinkCursor(X,Y);
  }

  // keep blinking snake where it already is
  else{
    lcd.setCursor(X, Y);
    lcd.write(' ');
    blinkCursor(X,Y);
  }

  // update rate 100ms
  delay(100);
}

// cursor function
void blinkCursor(int X_cor, int Y_cor){
  int X = X_cor;
  int Y = Y_cor;
  lcd.createChar(1, snake);
  lcd.setCursor(X, Y);
  lcd.write(byte(1));
}