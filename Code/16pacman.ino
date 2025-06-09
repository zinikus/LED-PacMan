//ANIMATED PACMAN GHOST LED

#include "FastLED.h"

#define NUM_LEDS 256
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(10); //Number 0-255
  FastLED.clear();
}


int eyes_seconds = 2;
int reg_ghost_seconds = 10;

int feet_delay = 220; //delay in ms b/w feet v1 v2
int eye_loop = (eyes_seconds*1000)/feet_delay; // how many times to look left and right before switching 

int reg_ghost_loop = reg_ghost_seconds/eyes_seconds; 
int sad_ghost_loop = 50;
int sad_ghost_blink_loop = 10;




int body[] = {
5,6,7,8,9,10,19,20,21,22,
23,24,25,26,27,28,34,35,36,37,
38,39,40,41,42,43,44,45,49,50,
51,52,53,54,55,56,57,58,59,60,
61,62,65,66,67,68,69,70,71,72,
73,74,75,76,77,78,80,81,82,83,
84,85,86,87,88,89,90,91,92,93,
94,95,96,97,98,99,100,101,102,103,
104,105,106,107,108,109,110,111,112,113,
114,115,116,117,118,119,120,121,122,123,
124,125,126,127,128,129,130,131,132,133,
134,135,136,137,138,139,140,141,142,143,
144,145,146,147,148,149,150,151,152,153,
154,155,156,157,158,159,160,161,162,163,
164,165,166,167,168,169,170,171,172,173,
174,175,177,178,179,180,181,182,183,184,
185,186,187,188,189,190,193,194,195,196,
197,198,199,200,201,202,203,204,205,206,
210,211,212,213,214,215,216,217,218,219,
220,221,227,228,229,230,231,232,233,234,
235,236,245,246,247,248,249,250
};

int mouth_half_open[] = {
5,6,7,8,9,10,19,20,21,22,
23,24,25,26,27,28,35,36,37,38,
39,40,41,42,43,44,52,53,54,55,
56,57,58,59,68,69,70,71,72,73,
74,75,85,86,87,88,89,90,101,102,
103,104,105,106,118,119,120,121,134,135,
136,137,151,152
};

int mouth_open[] = {
5,6,7,8,9,10,19,20,21,22,
23,24,25,26,27,28,34,35,36,37,
38,39,40,41,42,43,44,45,49,50,
51,52,53,54,55,56,57,58,59,60,
61,62,65,66,67,68,69,70,71,72,
73,74,75,76,77,78,82,83,84,85,
86,87,88,89,90,91,92,93,99,100,
101,102,103,104,105,106,107,108,116,117,
118,119,120,121,122,123,133,134,135,136,
137,138,150,151,152,153
};

int filler[] = {
138,116,117,107,108,84,83,82,78,77,
76,49,50,51,45,153,133,122,123,100,
99,91,92,93,67,66,65,60,61,62,
34
};



void loop() {

    for(int i = 0; i < reg_ghost_loop; i++){

        for(int i = 0; i < eye_loop; i++){

            //BODY
            for (int i = 0; i < 208; i++){      //was 166
                  leds[body[i]] = CRGB::Yellow;
            }
            FastLED.show();
            delay(500);

            //MOUTH HALF OPEN
            for (int i = 0; i < 64; i++){      
                  leds[mouth_half_open[i]] = CRGB::Black;
            }
            FastLED.show();
            delay(500);

            //MOUTH OPEN
            for (int i = 0; i < 96; i++){      
                  leds[mouth_open[i]] = CRGB::Black;
            }
            FastLED.show();
            delay(500);

            //BODY
            for (int i = 0; i < 31; i++){      
                  leds[filler[i]] = CRGB::Yellow;
            }
            FastLED.show();
            delay(500);

/*            //MOUTH HALF OPEN
            for (int i = 0; i < 64; i++){      
                  leds[mouth_half_open[i]] = CRGB::Black;
            }
            FastLED.show();
            delay(500);
*/


         }  //end eye loop

    } //end ghost loop
}
