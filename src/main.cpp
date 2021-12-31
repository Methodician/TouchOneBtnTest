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

OneButton btnGreen(GREEN_WIRE, true);
OneButton btnWhite(WHITE_WIRE, true);
OneButton btnYellow(YELLOW_WIRE, true);
OneButton btnBlue(BLUE_WIRE, true);

void greenClick() {
  Serial.println("Green Click");
}

void btnClick(int btn) {
  Serial.print("Button ");
  Serial.print(btn);
  Serial.println(" Click");
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting up");

  btnGreen.attachClick(greenClick);
  btnWhite.attachClick([]() {
    btnClick(WHITE_WIRE);
  });
}

void loop() {
  btnGreen.tick();
  btnWhite.tick();
  // Serial.println("Loop");
  // put your main code here, to run repeatedly:
  delay(10);
}