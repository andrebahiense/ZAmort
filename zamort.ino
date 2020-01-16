#include <Keyboard.h>

int bot[] = {2, 3, 4, 5};
char key[] = {"asdf"};
int x;
int a;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  for (int i = 0; i < 4; i++) {
    pinMode(bot[i], INPUT);
  }
}

void loop() {

  for (x = 0; x < 4; x++) {//
    a = digitalRead(bot[x]);
    if (a == HIGH) {
      Keyboard.press(key[x]);
      //Serial.println(key[x]);
      delay(110);
    }
    else {
      Keyboard.releaseAll();
      //Serial.println("No");
    }
  }
}
