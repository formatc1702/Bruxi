const int emgPin = A0;
const int micPin = A1;

const int emgFallRate = 3;
const int micFallRate = 3;

int emgValue = 0;
int emgMaxValue = 0;
int emgMinValue = 0;
int emgAmpValue = 0;

int micValue = 0;
int micMaxValue = 0;
int micMinValue = 0;
int micAmpValue = 0;
int emgGraphValue = 0;
int micGraphValue = 0;

int loopCounter = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  emgValue = analogRead(emgPin);
  micValue = analogRead(micPin);

  if (emgValue >= emgMaxValue) {
    emgMaxValue = emgValue;
  } else {
    emgMaxValue -= emgFallRate;
  }
  if (emgValue <= emgMinValue) {
    emgMinValue = emgValue;
  } else {
    emgMinValue += emgFallRate;
  }
  emgMaxValue = max(0, emgMaxValue);
  emgMinValue = min(emgMinValue, emgMaxValue);
  emgAmpValue = emgMaxValue - emgMinValue;

  if (micValue >= micMaxValue) {
    micMaxValue = micValue;
  } else {
    micMaxValue -= micFallRate;
  }
  if (micValue <= micMinValue) {
    micMinValue = micValue;
  } else {
    micMinValue += micFallRate;
  }
  micMaxValue = max(0, micMaxValue);
  micMinValue = min(micMinValue, micMaxValue);
  micAmpValue = micMaxValue - micMinValue;


  loopCounter++;
  if (loopCounter > 20) {
    ///*
    Serial.print(emgAmpValue);
    Serial.print('\t');
    Serial.print(micAmpValue);
    Serial.println();
    // */


    emgGraphValue = map(emgAmpValue, 0, 1023, 0, 32);
    micGraphValue = map(micAmpValue, 0, 1023, 0, 32);

    /*
    for (int i = 0; i < emgGraphValue; i++) {
    Serial.print(' ');
    }
    Serial.print('|');
    for (int i = emgGraphValue; i < 32; i++) {
    Serial.print(' ');
    }
    Serial.print('\t');

    for (int i = 0; i < micGraphValue; i++) {
    Serial.print(' ');
    }
    Serial.print('|');
    for (int i = micGraphValue; i < 32; i++) {
    Serial.print(' ');
    }
    Serial.println();
    // */

    loopCounter = 0;
  }

  delay(5);
}
