#include "Adafruit_NeoTrellis.h"

Adafruit_NeoTrellis trellis;

int boardState[] = {
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0
};

int tttSpaceNumbers[] = {
  0, 1, 2,
  4, 5, 6,
  8, 9, 10
};

//define a callback for key presses
TrellisCallback blink(keyEvent evt){
  // Check is the pad pressed?
  if (evt.bit.EDGE == SEESAW_KEYPAD_EDGE_RISING) {
    int space = evt.bit.NUM;
    Serial.print("space number ");
    Serial.println(space);
    if (space == 15) {
      for (int i = 0; i < 16; i++) {
        boardState[tttSpaceNumbers[i]] = 0;
        trellis.pixels.setPixelColor(tttSpaceNumbers[i], 0);
      }
    } else {
      int isTttSpace = 0;
      for (int i = 0; i < 9; i++) {
        if (tttSpaceNumbers[i] == space) {
          isTttSpace = 1;
        }
      }
      if (boardState[space] == 0 && isTttSpace == 1) {
        int turnsTaken = 0;
        for (int i = 0; i < 16; i++) {
          if (boardState[i] > 0) {
            turnsTaken += 1;
          }
        }
        if (turnsTaken % 2 == 0) {
          trellis.pixels.setPixelColor(space, trellis.pixels.Color(0, 255, 0));
        } else {
          trellis.pixels.setPixelColor(space, trellis.pixels.Color(0, 0, 255));
        }
        
        boardState[space] = 1;
      }
    }
  }

  // Turn on/off the neopixels
  trellis.pixels.show();

  return 0;
}

void setup() {
  Serial.begin(9600);
  
  if (!trellis.begin()) {
    Serial.println("Could not start trellis, check wiring?");
    while(1);
  } else {
    Serial.println("NeoPixel Trellis started");
  }

  //activate all keys and set callbacks
  for(int i=0; i<NEO_TRELLIS_NUM_KEYS; i++){
    trellis.activateKey(i, SEESAW_KEYPAD_EDGE_RISING);
    trellis.activateKey(i, SEESAW_KEYPAD_EDGE_FALLING);
    trellis.registerCallback(i, blink);
  }
}

void loop() {
  trellis.read();  // interrupt management does all the work! :)
  
  delay(20); //the trellis has a resolution of around 60hz
}
