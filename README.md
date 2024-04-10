# Snake Game with Arduino and LCD

This Arduino project implements a simple snake game using an LCD display and push buttons. The game features a snake that moves around the screen, eating randomly placed "monsters" to score points. The player controls the snake's movement using push buttons.

# Hardware Requirements
- Arduino board (e.g., Arduino Uno)
- LCD display with I2C interface (e.g., 16x2 LiquidCrystal I2C)
- Push buttons (at least 4)
- Jumper wires
- Breadboard (optional)

## Software Requirements
- Arduino IDE
- LiquidCrystal_I2C library

## Installation and Setup
1. Connect the LCD display to the Arduino board using the I2C interface.
2. Connect the push buttons to the Arduino board.
3. Open the Arduino IDE and install the LiquidCrystal_I2C library if not already installed.
4. Copy the provided code into a new sketch in the Arduino IDE.
5. Upload the sketch to the Arduino board.

## How to Play
- Use Button 1 to move the snake left.
- Use Button 2 to move the snake right.
- Use Button 3 to move the snake up or down.
- Use Button 4 to reset the snake to the starting position (0,0).
- The snake will automatically blink at its current position.
- Each time the snake eats a monster (reaches the same position), the score increases by one.

## Code Explanation

### Libraries Used
- **Wire.h:** Library for I2C communication.
- **LiquidCrystal_I2C.h:** Library for interfacing with LCD using I2C.

### Global Variables
- **counter:** Counter for timing events.
- **match:** Flag indicating if the snake and monster are at the same position.
- **score:** Game score, initialized to -1.
- **X, Y:** Current position of the snake.
- **prev_X, prev_Y:** Previous position of the snake.
- **monster_X, monster_Y:** Current position of the monster.
- **monster_prev_X, monster_prev_Y:** Previous position of the monster.
- **snake:** Custom character bitmap for the snake.
- **monster:** Custom character bitmap for the monster.

### Functions
- **setup():** Initializes the LCD, sets pin modes for input buttons, prints initial message and score, and randomizes the seed value.
- **loop():** Main loop of the game. Reads input from buttons, updates snake position, checks for collisions, updates score, and displays everything on the LCD.
- **blinkCursor(int X_cor, int Y_cor):** Function to blink the snake at a given position on the LCD.

## Credits
This project is inspired by various Arduino-based snake game projects available online. The code is written by [Your Name] and is free to use and modify.

