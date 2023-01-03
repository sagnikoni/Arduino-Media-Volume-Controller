// Download the HID and FAST LED Library before compiling
#include <HID-Project.h>
#include <HID-Settings.h>
#include <FastLED.h>   // https://github.com/FastLED/FastLED
#define NUM_LEDS 16 //Number of LEDS in ARGB Ring
#define LED_PIN 6 // To ARGB LED Data Pin
#define DATA0 2 // To Encoder Data 0 - Interrupt Pin
#define DATA1 3 // To Encoder Data 1 - Interrupt Pin
#define MUTE 7 // To Touch Switch Data pin Mute
#define NEXT 4 // To Touch Switch Data pin Mute
#define PAUSE 8 // To Touch Switch Data pin Mute
#define PREVIOUS 5 // To Touch Switch Data pin Mute
#define BRIGHTNESS 50 // RGB LED Brightness
#define SATURATION 125 // RGB LED Saturation Level
#define FRAMES_PER_SECOND  60 // LED Animation FPS



CRGB leds[NUM_LEDS];


int oldData0 = 0, oldData1 = 0, oldButtonState = 0, oldButtonState1 = 0, oldButtonState2 = 0, oldButtonState3 = 0; // To store the state of encoder

int i = constrain(i, 1, 50); //To store the encoder counter value Maximum limit 50

int val;
int triggerAnimation = 0;
int b; // To store the divided value if encoder to match the Number of LEDs


void setup() {
  
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);


   Serial.begin(9600);
    pinMode(MUTE, INPUT);
    pinMode(DATA0, INPUT);
    pinMode(DATA1, INPUT);
    pinMode(NEXT, INPUT);
    pinMode(PREVIOUS, INPUT);
    pinMode(PAUSE, INPUT);
    
    digitalWrite(MUTE, LOW);
    digitalWrite(DATA0, LOW);
    digitalWrite(DATA1, LOW);
    digitalWrite(NEXT, LOW);
    digitalWrite(PREVIOUS, LOW);
    digitalWrite(PAUSE, LOW);

    attachInterrupt(digitalPinToInterrupt(DATA0), volume, CHANGE);
    attachInterrupt(digitalPinToInterrupt(DATA1), volume, CHANGE);  
    FastLED.setBrightness(BRIGHTNESS);
    delay(3000); 

    Consumer.begin();
  
}
//Setup for LED Animation
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0;


void loop()
{
  
//MUTE function

  int newButtonState = digitalRead(MUTE);
    
  if(oldButtonState != newButtonState)
    {
      if(newButtonState == 1)
      {    
       
         
        val = 0;
         Serial.println("Count reset!");
        // See HID Project documentation for more Consumer keys
        Consumer.write(MEDIA_VOL_MUTE);

      leds[15] = CRGB::Black;
      leds[14] = CRGB::Black;
      leds[13] = CRGB::Black;
      leds[12] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[10] = CRGB::Black;
      leds[9] = CRGB::Black;
      leds[8] = CRGB::Black;
      leds[7] = CRGB::Black;
      leds[6] = CRGB::Black;
      leds[5] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[0] = CRGB::Black;
      FastLED.show();
      delay(15);
      

             leds[0] = CRGB (0, 4, 217);
      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(15);
      
            leds[1] = CRGB (0, 80, 217);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[2] = CRGB (0, 166, 217);
            FastLED.setBrightness(50);
      FastLED.show();
      delay(15);
      
            leds[3] = CRGB (0, 217, 2171);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[4] = CRGB (0, 217, 174);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
            leds[5] = CRGB (0, 217, 116);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[6] = CRGB (0, 217, 58);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[7] = CRGB (22, 217, 0);
      FastLED.show();
      delay(15);
      
            leds[8] = CRGB (134, 217, 0);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[9] = CRGB (166, 217, 0);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[10] = CRGB (166, 217, 0);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[11] = CRGB (195, 217, 0);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[12] = CRGB (217, 213, 0);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[13] = CRGB (217, 192, 0);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[14] = CRGB (217, 112, 0);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
            leds[15] = CRGB (217, 80, 0);
            FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();
      delay(15);
      
      leds[15] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[14] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[13] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[12] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[11] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[10] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[9] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[8] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[7] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[6] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[5] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[4] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[3] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[2] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[1] = CRGB::Black;
      FastLED.show();
      delay(15);
      leds[0] = CRGB::Black;
      FastLED.show();
      delay(2);
      
     FastLED.clear(); 
    }

      oldButtonState = newButtonState;

    }


//MEDIA_NEXT right


  int newButtonState1 = digitalRead(NEXT);
    
  if(oldButtonState1 != newButtonState1)
    {
      // If it did and the new button state is 1 (button pressed down)
      if(newButtonState1 == 1)
      {    
         
        val = 0;
         Serial.println("Count reset!");
        // See HID Project documentation for more Consumer keys
        Consumer.write(MEDIA_NEXT);


      leds[15] = CRGB::Black;
      leds[14] = CRGB::Black;
      leds[13] = CRGB::Black;
      leds[12] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[10] = CRGB::Black;
      leds[9] = CRGB::Black;
      leds[8] = CRGB::Black;
      leds[7] = CRGB::Black;
      leds[6] = CRGB::Black;
      leds[5] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[0] = CRGB::Black;
      FastLED.show();
      delay(15);

             leds[8] = CRGB (0, 255, 195);

leds[15] = CRGB (0, 255, 195);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(50);
      
leds[9] = CRGB (38, 255, 00);

leds[14] = CRGB (38, 255, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(50);

leds[10] = CRGB (238, 255, 0);

leds[13] = CRGB (238, 255, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(50);

leds[11] = CRGB (255, 90, 0);

leds[12] = CRGB (255, 90, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(70);


//LED OFF animation coded

leds[8] = CRGB::Black;

leds[15] = CRGB::Black;

      FastLED.show();      
      delay(50);
      
leds[9] = CRGB::Black;

leds[14] = CRGB::Black;

      FastLED.show();      
      delay(50);

leds[10] = CRGB::Black;

leds[13] = CRGB::Black;

      FastLED.show();      
      delay(70);

leds[11] = CRGB (255, 10, 0);

leds[12] = CRGB (255, 10, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(50);

leds[11] = CRGB::Black;

leds[12] = CRGB::Black;

      FastLED.show();      
      delay(50);
FastLED.clear();
      
    }

      oldButtonState1 = newButtonState1;

    }


//MEDIA_PREVIOUS Left

  int newButtonState2 = digitalRead(PREVIOUS);
    
  if(oldButtonState2 != newButtonState2)
    {
      // If it did and the new button state is 1 (button pressed down)
      if(newButtonState2 == 1)
      {    

        
        
        val = 0;
         Serial.println("Count reset!");
        // See HID Project documentation for more Consumer keys
        Consumer.write(MEDIA_PREVIOUS);


       leds[15] = CRGB::Black;
      leds[14] = CRGB::Black;
      leds[13] = CRGB::Black;
      leds[12] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[10] = CRGB::Black;
      leds[9] = CRGB::Black;
      leds[8] = CRGB::Black;
      leds[7] = CRGB::Black;
      leds[6] = CRGB::Black;
      leds[5] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[0] = CRGB::Black;
      FastLED.show();
      delay(15);

leds[7] = CRGB (0, 255, 195);

leds[0] = CRGB (0, 255, 195);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(50);
      
leds[6] = CRGB (38, 255, 00);

leds[1] = CRGB (38, 255, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(50);

leds[5] = CRGB (238, 255, 0);

leds[2] = CRGB (238, 255, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(50);

leds[4] = CRGB (255, 90, 0);

leds[3] = CRGB (255, 90, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(70);


//LED OFF animation coded

leds[7] = CRGB::Black;

leds[0] = CRGB::Black;

      FastLED.show();      
      delay(50);
      
leds[6] = CRGB::Black;

leds[1] = CRGB::Black;

      FastLED.show();      
      delay(50);

leds[5] = CRGB::Black;

leds[2] = CRGB::Black;

      FastLED.show();      
      delay(70);

leds[4] = CRGB (255, 10, 0);

leds[3] = CRGB (255, 10, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(50);

leds[4] = CRGB::Black;

leds[3] = CRGB::Black;

      FastLED.show();      
      delay(50);
FastLED.clear();

    }

      oldButtonState2 = newButtonState2;

    }

  //Midea PAUSE PLAY

      int newButtonState3 = digitalRead(PAUSE);
    
  if(oldButtonState3 != newButtonState3)
    {
      // If it did and the new button state is 1 (button pressed down)
      if(newButtonState3 == 1)
      {    
                
        val = 0;
         Serial.println("Count reset!");
        // See HID Project documentation for more Consumer keys
        Consumer.write(MEDIA_PLAY_PAUSE);


       leds[15] = CRGB::Black;
      leds[14] = CRGB::Black;
      leds[13] = CRGB::Black;
      leds[12] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[10] = CRGB::Black;
      leds[9] = CRGB::Black;
      leds[8] = CRGB::Black;
      leds[7] = CRGB::Black;
      leds[6] = CRGB::Black;
      leds[5] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[0] = CRGB::Black;
      FastLED.show();
      delay(15);


leds[15] = CRGB (255, 170, 0);

leds[0] = CRGB (255, 170, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);
      
leds[14] = CRGB (255, 247, 0);

leds[1] = CRGB (255, 247, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[13] = CRGB (195, 255, 0);

leds[2] = CRGB (195, 255, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[12] = CRGB (72, 255, 0);

leds[3] = CRGB (72, 255, 0);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[11] = CRGB (0, 255, 94);

leds[4] = CRGB (0, 255, 94);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[10] = CRGB (0, 255, 242);

leds[5] = CRGB (0, 255, 242);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);
leds[9] = CRGB (0, 174, 255);

leds[6] = CRGB (0, 174, 255);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[8] = CRGB (123, 0, 255);

leds[7] = CRGB (123, 0, 255);

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[8] = CRGB::Black;

leds[7] = CRGB::Black;

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[9] = CRGB::Black;

leds[6] = CRGB::Black;

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[10] = CRGB::Black;

leds[5] = CRGB::Black;

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[11] = CRGB::Black;

leds[4] = CRGB::Black;

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[12] = CRGB::Black;

leds[3] = CRGB::Black;

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[13] = CRGB::Black;

leds[2] = CRGB::Black;
      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[14] = CRGB::Black;

leds[1] = CRGB::Black;

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

leds[15] = CRGB::Black;

leds[0] = CRGB::Black;

      FastLED.setBrightness(BRIGHTNESS);
      FastLED.show();      
      delay(25);

    }

      oldButtonState3 = newButtonState3;

    }

        if (triggerAnimation == 1)
        {
           ledAnimation2();
                           
              }
       if (triggerAnimation == 0)
     {
     
      ledAnimation();
        
    }

  
}




void volume() // Encoder Interrupt Function
{
//Initalise Timer 
TIMSK1 |= (1<<TOIE1);
TCCR1A &= (~(1<<WGM10)) & (~(1<<WGM11));
TCCR1B &= (~(1<<WGM12)) & (~(1<<WGM13));
TCCR1B |= (1<<CS12) | (1<<CS10);
TCCR1B &= (~(1<<CS11));
TCNT1 = 0;

  int newData0 = digitalRead(DATA0);
  int newData1 = digitalRead(DATA1);
       
   if(newData0 != oldData0 || newData1 != oldData1)
    {    
      // Check both data pins and check if the state changed
      // compared to the last cycle
      if(!oldData0 && !oldData1 && !newData0 && newData1)
      {
        triggerAnimation = 1;
        delay(5);
        i = max(-1, min(i -1, 50));

          Serial.println(i);
          Consumer.write(MEDIA_VOLUME_DOWN);     
          Serial.println(triggerAnimation);
                 
          b = i/3;
       }
    
        
      if(!oldData0 && !oldData1 && newData0 && !newData1)
      {
        triggerAnimation = 1;
        delay(0);
        i = max(1, min(i +1, 50));
        
          Serial.println(i);
          Consumer.write(MEDIA_VOLUME_UP); 
                       
          b = i/3;
       }
      
      oldData0 = newData0;
      oldData1 = newData1;     
      
      delay(5); // Small delay for de-bouncing
            
      }
      
  }

ISR(TIMER1_OVF_vect)
  {
b = 16;
TCNT1 = 0;

TCCR1B &= ~(1<< CS12);
TCCR1B &= ~(1<< CS11);
TCCR1B &= ~(1<< CS10);

triggerAnimation = 0;
  }

        void ledAnimation2()
     
        {
          
   gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();  
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND); 
    EVERY_N_MILLISECONDS( 20 ) { gHue++; }
     EVERY_N_MILLISECONDS( 0 ) {FastLED.clear();}
    rainbow();
          }

   void ledAnimation()
      
  {

  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();  
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND); 

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; }
    EVERY_N_SECONDS( 10 ) {      
    nextPattern(); } // change patterns periodically
  }

        


#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, b, gHue, 7);
}


void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(b) ] += CRGB::White;
  }
}

void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, b, 10);
  int pos = random16(b);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, b, 20);
  int pos = beatsin16( 13, 0, b-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < b; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, b, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, b-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}







  
  
