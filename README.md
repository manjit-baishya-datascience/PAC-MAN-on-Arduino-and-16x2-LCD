# **Snake Game in Arduino and I2C LCD Display**
![header](https://github.com/manjit-baishya-datascience/Snake-Game-on-Arduino-and-16x2-LCD/assets/127611924/29c0ed55-34ba-4521-a0fc-91702cddf59f)
This Arduino project implements a simple PAC-MAN game using an LCD display and push buttons. The game features a snake that moves around the screen, eating randomly placed "monsters" to score points. The player controls the snake's movement using push buttons.

### **Hardware Requirements**
- Arduino board (e.g., Arduino Uno)
- LCD display with I2C interface (e.g., 16x2 LiquidCrystal I2C)
- Push buttons (at least 4)
- Jumper wires
- Breadboard (optional)

### **Software Requirements**
- Arduino IDE
- LiquidCrystal_I2C library (I2C_lib-1.1.2.zip)

### **Pin Configuration**
- Connect a `10kΩ` resistor across the `GND` pins of each `Push Button(PB)`.

=======================================================
- **Push Button Signal Out** to **Arduino PIN** connections are as follows:
- `PB 1` --> `PIN 2`
- `PB 2` --> `PIN 4`
- `PB 3` --> `PIN 7`
- `PB 4` --> `PIN 8`

=======================================================
- **LCD** to **Arduino** PIN connections are as follows:
- `SCL` --> `A5`
- `SDA` --> `A4`
- `VCC` --> `5V`
- `GND` --> `GND`

=======================================================

## **Installation and Setup**
1. Connect the `LCD display` to the `Arduino` board using the `I2C` interface.
2. Connect the push buttons to the Arduino board.
3. Open the Arduino IDE and install the LiquidCrystal_I2C library if not already installed.
4. Copy the provided code into a new sketch in the Arduino IDE.
5. Upload the sketch to the Arduino board.

## **How to Play**
- Use `Button 1` to move the snake `left`.
- Use `Button 2` to move the snake `right`.
- Use `Button 3` to move the snake `up` or `down`.
- Use `Button 4` to reset the snake to the starting position `(0,0)`.
- The snake will automatically blink at its current position.
- Each time the snake eats a monster, the score increases by one and the monster appears at a new location.

## **Code Explanation**

### **Libraries Used**
- **Wire.h:** Library for I2C communication.
- **LiquidCrystal_I2C.h:** Library for interfacing with LCD using I2C.

### **Global Variables**
- **counter:** Counter for dealying the changing of positions of the monster.
- **match:** Flag indicating if the snake and monster are at the same position.
- **score:** Game score, initialized to -1.
- **X, Y:** Current position of the snake.
- **prev_X, prev_Y:** Previous position of the snake.
- **monster_X, monster_Y:** Current position of the monster.
- **monster_prev_X, monster_prev_Y:** Previous position of the monster.
- **snake:** Custom character bitmap for the snake.
- **monster:** Custom character bitmap for the monster.

### **Functions**
- **setup():** Initializes the LCD, sets pin modes for input buttons, prints initial message and score, and randomizes the seed value.
- **loop():** Main loop of the game. Reads input from buttons, updates snake position, checks for collisions, updates score, and displays everything on the LCD.
- **blinkCursor(int X_cor, int Y_cor):** Function to blink the snake at a given position on the LCD.