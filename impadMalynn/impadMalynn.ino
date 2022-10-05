// ESP32-Enabled GamePad
// Malynn Price || Sept 26 2022

// Libraries & Definitions
#define BOUNCE_WITH_PROMPT_DETECTION                            // Provides faster debouncing for precise gameplay
#include <Bounce2.h>                                            // Bounce2 Library
#include <Arduino.h>                                            // Arduino Library
#include <BleGamepad.h>                                         // Bluetooth Gamepad Library
BleGamepad bleGamepad("Impad", "Malynn Price", 100);            // Replace Device Name / Manufacturer w/ your info

void setup() {
  Serial.begin(115200);

  initButtons();                                                // Initialize All Buttons
  initJoysticks();                                              // Initialize All Joysticks
  initBattery();                                                // Initialize Battery

  BleGamepadConfiguration bleGamepadConfig;                     // Create a GamePad Configuration
  bleGamepadConfig.setButtonCount(15);                          // Declare the Button Count (15)
  bleGamepad.begin(&bleGamepadConfig);                          // Begin Bluetooth Communication
}

void loop() {
  if (bleGamepad.isConnected()) {                               // If the GamePad is connected to the Computer
    updateBattery();                                            // Update Battery Status
    updateButtons();                                            // Update Button States
    updateJoysticks();                                          // Update Joystick Status
  }
}
