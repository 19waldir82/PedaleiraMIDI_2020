#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define pushButton1 2
#define pushButton2 3
boolean hiLow[] = {false, false};
boolean estadoAnt[] = {true, true};
boolean buttonState[] = {false, false};
boolean note[] = {false, false};
byte lastAnalogValue[] = {127, 127, 127, 127, 127, 127, 127};


void setup() {
  MIDI.begin(4);
  Serial.begin(115200);
  
  pinMode(pushButton1, INPUT_PULLUP);
  pinMode(pushButton2, INPUT_PULLUP);
}


void loop() {


///////////////////////Analógico///////////////////////////


  byte analogValue1 = analogRead(A0)/8; 
  if ((analogValue1-lastAnalogValue[0]) > 1 || (analogValue1-lastAnalogValue[0]) < -1) {
    if (analogValue1 != lastAnalogValue[0]) {
      MIDI.sendControlChange(1, analogValue1, 1);
      lastAnalogValue[0] = analogValue1;
    }
  }

  byte analogValue2 = analogRead(A1)/8; 
  if ((analogValue2-lastAnalogValue[1]) > 1 || (analogValue2-lastAnalogValue[1]) < -1) {
    if (analogValue2 != lastAnalogValue[1]) {
      MIDI.sendControlChange(2, analogValue2, 1);
      lastAnalogValue[1] = analogValue2;
    }
  }

  byte analogValue3 = analogRead(A2)/8; 
  if ((analogValue3-lastAnalogValue[2]) > 1 || (analogValue3-lastAnalogValue[2]) < -1) {
    if (analogValue3 != lastAnalogValue[2]) {
      MIDI.sendControlChange(3, analogValue3, 1);
      lastAnalogValue[2] = analogValue3;
    }
  }

  byte analogValue4 = analogRead(A3)/8; 
  if ((analogValue4-lastAnalogValue[3]) > 1 || (analogValue4-lastAnalogValue[3]) < -1) {
    if (analogValue4 != lastAnalogValue[3]) {
      MIDI.sendControlChange(4, analogValue4, 1);
      lastAnalogValue[3] = analogValue4;
    }
  }

  byte analogValue5 = analogRead(A4)/8; 
  if ((analogValue5-lastAnalogValue[4]) > 1 || (analogValue5-lastAnalogValue[4]) < -1) {
    if (analogValue5 != lastAnalogValue[4]) {
      MIDI.sendControlChange(5, analogValue5, 1);
      lastAnalogValue[4] = analogValue5;
    }
  }

  byte analogValue6 = analogRead(A5)/8; 
  if ((analogValue6-lastAnalogValue[5]) > 1 || (analogValue6-lastAnalogValue[5]) < -1) {
    if (analogValue6 != lastAnalogValue[5]) {
      MIDI.sendControlChange(6, analogValue6, 1);
      lastAnalogValue[5] = analogValue6;
    }
  }

  byte analogValue7 = analogRead(A6)/8; 
  if ((analogValue7-lastAnalogValue[6]) > 1 || (analogValue7-lastAnalogValue[6]) < -1) {
    if (analogValue7 != lastAnalogValue[6]) {
      MIDI.sendControlChange(7, analogValue7, 1);
      lastAnalogValue[6] = analogValue7;
    }
  }


///////////////////Digital//////////////////////////


  buttonState[0] = digitalRead(pushButton1);
  if (buttonState[0] == false){
    if (estadoAnt[0] == true){
      hiLow[0] = !hiLow[0];
      estadoAnt[0] = buttonState[0];
      }
    
    if (hiLow[0] && !note[0]) {
        MIDI.sendControlChange(8,127,1);  
        note[0] = true;
    }

    if (!hiLow[0] && !note[0]) {
        MIDI.sendControlChange(8,0,1);
        note[0] = true; 
    }
    
  }else {
    estadoAnt[0] = true;
    note[0] = false;
    }

  buttonState[1] = digitalRead(pushButton2);
  if (buttonState[1] == false){
    if (estadoAnt[1] == true){
      hiLow[1] = !hiLow[1];
      estadoAnt[1] = buttonState[1];
      }
    
    if (hiLow[1] && !note[1]) {
        MIDI.sendControlChange(9,127,1);  
        note[1] = true;
    }

    if (!hiLow[1] && !note[1]) {
        MIDI.sendControlChange(9,0,1);
        note[1] = true; 
    }
    
  }else {
    estadoAnt[1] = true;
    note[1] = false;
    }
    delay(10);
}
