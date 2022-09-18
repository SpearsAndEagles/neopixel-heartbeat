#include <Adafruit_NeoPixel.h>
#define PIN 6               
#define N_LEDS 23     
#define LEN 15
#define MAX 255
#define MIN 0
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
uint8_t mod;

static void chase() {  
  for(uint8_t i=0; i<=strip.numPixels(); i+=LEN) {
    uint8_t running_total = MAX;
    for(uint8_t j=LEN; j>0;j--){
      strip.setPixelColor((j+mod)%LEN+i, strip.Color(running_total, 0, 0));
      running_total = running_total / 2 + 1;
    }
  }
}

void setup() {
  strip.begin();
  mod = LEN - 1;
}
void loop() {
  chase();
  strip.show();
  delay(70);
  mod++;
  mod = mod % LEN;
}
