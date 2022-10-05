// Joystick Functions
int joyPins[4] = {25, 33, 27, 26};   // Stores the GPIO pin assignemnts for LX, LY, RX, RY
int joyPos[4] = {0, 0, 0, 0};        // Store current joystick positions
int joyInv[4] = {-1, 1, -1, 1};      // Invert joystick positions (set -1 to invert)
int joyThresh = 750;                 // How much value must change before update

// initJoysticks loops through the array of joystick pins and declares their pinMode them as inputs.
void initJoysticks() {
  for (int i = 0; i < 4; i++) {
    pinMode(joyPins[i], INPUT);
  }
}

// updateJoysticks loops through the array of joysticks and analog reads their position.
// It then maps their value (0 - 4095) to a PC-compatible value (32737 to -32737)
// That mapped value is then compared to the previous value of the joystick axis.
// If the difference between those two values is greater than the threshold,
// then previous value of the joystick axis is updated and the isUpdate boolean
// is set set to true to push an updated status to the PC
void updateJoysticks() {
  boolean isUpdate = false;                      // Should joystick update?

  for (int i = 0; i < 4; i++) {
    int theReading = analogRead(joyPins[i]);
    int mappedReading = map(theReading, 0, 4095, 32737, -32737) * joyInv[i];
    int prevVal = joyPos[i];
    
    if (abs(mappedReading - prevVal) > joyThresh) {
      joyPos[i] = mappedReading;
      isUpdate = true;
    }
  }

  if (isUpdate) {
    bleGamepad.setAxes(joyPos[0], joyPos[1], joyPos[2], 0, joyPos[3], 0, 0, 0); // LX, LY, RX, RY, LT, RT, S1, S2
  }
}
