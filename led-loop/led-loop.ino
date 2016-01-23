/*     ---------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code             |
 *     |  CIRC-02 .: 8 LED Fun :. (Multiple LEDs)   |
 *     ---------------------------------------------------------
 *  
 *  A pimped-up, configurable, knight rider version of the default ardx led animation.
 *
 *
 */


int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; 
                                                                      
                                   
void setup() {
  
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 8; i++){   
      pinMode(ledPins[i],OUTPUT); 
  }                                  

}
 

void loop() 
{
  int tailLen = 8; // length of the led 'tail'
  int ledPinAmount = sizeof(ledPins); // length of the pin array 
  int delayBetweenCycles = 500; // in ms
  int delayBetweenDirectionChanges = 100;
  int delayBetweenIterations = 20; // in ms
  int cycleLen = ledPinAmount + tailLen; // length of the 'forward' part of the cycle

  for(int i = 0; i <= cycleLen * 2; i++) {

    bool dir = i < cycleLen; // true - forward, false - backward

    if(i == cycleLen) delay(delayBetweenDirectionChanges); // wait between direction changes
    
    int lightIdx = dir ? i:cycleLen * 2 - tailLen - i; // the led index to light up
    int dimIdx = lightIdx + (!dir ? tailLen:-tailLen); // the led index to dim
    
    // if the tail if filled, dim the last LED
    bool tailFilled = dir ? lightIdx + 1 > tailLen : ledPinAmount - lightIdx > tailLen;    
    
    // if a LED comes into range, light it up
    bool inLedRange = lightIdx < ledPinAmount && lightIdx >= 0;
    
    if(inLedRange) digitalWrite(ledPins[lightIdx], HIGH);    
    if(tailFilled) digitalWrite(ledPins[dimIdx], LOW);
    
    delay(delayBetweenIterations);

  }

  delay(delayBetweenCycles);
}
 
