// Button Control
int buttonPins[15] = {36, 39, 35, 32, 12, 13, 23, 22, 21, 19, 18, 16, 4, 2, 15 };    // Fill in { } with list of Button pins
int buttonNums[15] = {2, 1, 14, 5, 12, 15, 7, 10, 11, 9, 8, 4, 6, 3, 13};            // Store Button Number Assignments (1 - 15)
Bounce * buttons = new Bounce[15];                                                   // Creates an array of Bounce objects

// initButtons loops through the array of Bounce2 buttons and attaches them as inputs.
// It also sets an interval of 5ms for responsiveness
void initButtons() {
  for (int i = 0; i < 15; i++) {
    buttons[i].attach(buttonPins[i], INPUT);  // Attaches the buttons in the array
    buttons[i].interval(5);                   // Interval for buttons in the array
  }
}

// updateButtons loops through the array of Bounce2 buttons and updates them.
// If the buttons rose, then the respective button is pressed in the bleGamepad library
// If the buttons fell, then the respective button is released in the bleGamepad library
void updateButtons() {
  for (int i = 0; i < 15; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      bleGamepad.press(buttonNums[i]);
    }
    if (buttons[i].fell()) {
      bleGamepad.release(buttonNums[i]);
    }
  }
}
