#include <Arduino.h>
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

class Btn {
  public:
    Btn(
      const int16_t pin,
      const bool activeLow,
      const bool pullupActive
    ) {
      _pin = pin;
      _buttonPressed
    }

  private:
    int16_t _pin;
    uint16_t _debounceTicks = 50; // ms for debounce time
    uint16_t _clickTicks = 400;   // ms before click is detected
    uint16_t _pressTicks = 800;   // ms before long press is detected



    callbackFunction _clickFunc = NULL;

}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}