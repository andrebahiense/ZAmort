//----------------------------------------------------------------------------------------------------------
// ZAmort - AUSS & AUSS Game Controller
// by Andre Bahiense. January 2020.
//
// This is the code for the ZAmort game controller, designed for the AUSS & AUSS transmedia experience,
// created by NIKIMA.
// Please visit http://www.aussnauss.com/ for more information.
//----------------------------------------------------------------------------------------------------------

#include <Keyboard.h>

int bot[] = {2, 3, 4, 5};
char key[] = {"asdf"};
int stateArray[] = {0, 0, 0, 0};
bool buttonState = true;
bool lastButtonState = false;
int x, y;

void setup() {
  Serial.begin(300);
  Keyboard.begin();
  for (int i = 0; i < 4; i++) {
    pinMode(bot[i], INPUT);
  }
}

void loop() {

  for (x = 0; x < 4; x++) {
    stateArray[x] = digitalRead(bot[x]);
    delay(7);
  }

  if (stateArray[0] == HIGH || stateArray[1] == HIGH || stateArray[2] == HIGH || stateArray[3] == HIGH) {
    buttonState = true;
    if (buttonState != lastButtonState) {
      for (y = 0; y < 4; y++) {
        if (stateArray[y] == HIGH) {
          Keyboard.press(key[y]);
          Keyboard.releaseAll();
        }
        else {
          Keyboard.releaseAll();
        }
      }
    }
  }

  else {
    Keyboard.releaseAll();
    buttonState = false;
  }
  lastButtonState = buttonState;
}
