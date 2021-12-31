#include <Arduino.h>
#include <OneButton.h>
#include <Adafruit_CircuitPlayground.h>

//  A0 p?
//  A1 p6
//  A2 p9
//  A3 p10
//  A4 p3
//  A5 p2
//  A6 p0
//  A7 p1



#define GREEN_WIRE     3 // A4
#define GREEN_PIXEL    0
#define WHITE_WIRE     2 // A5
#define WHITE_PIXEL    1
#define YELLOW_WIRE    0 // A6
#define YELLOW_PIXEL   3
#define BLUE_WIRE      1 // A7
#define BLUE_PIXEL     4

#define DEBOUNCE_TIME  90

uint16_t recentClicks[10];
uint8_t lastClickEl = 0;

OneButton btnGreen(GREEN_WIRE, true);
OneButton btnWhite(WHITE_WIRE, true);
OneButton btnYellow(YELLOW_WIRE, true);
OneButton btnBlue(BLUE_WIRE, true);

void btnClick(uint16_t btnPin) {
  recentClicks[lastClickEl] = btnPin;
  if(lastClickEl < 9) {
    lastClickEl++;
  } else {
    lastClickEl = 0;
  }

}


void setup() {
  Serial.begin(9600);

  btnGreen.attachClick([]() {
    btnClick(btnGreen.getPin());
  });
  btnWhite.attachClick([]() {
    btnClick(btnWhite.getPin());
  });
}

void loop() {
  btnGreen.tick();
  btnWhite.tick();
  // Serial.println("Loop");
  Serial.println();
  for(uint16_t i = 0; i < 10; i++) {
    Serial.print(recentClicks[i]);
    Serial.print("-");
  }
  Serial.println();
  delay(10);
}