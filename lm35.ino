#define ADC_VREF_mV    1100.0
#define ADC_RESOLUTION 1024.0
#define PIN_LM35       A1

#define PIN_LM35_2     A2

void setup() {
  Serial.begin(9600);
  // switch to Internal 1.1V Reference
  analogReference(INTERNAL);
}

void loop() {
  int adcVal = analogRead(PIN_LM35);
  float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
  float tempC = milliVolt / 10;

  int adcVal_2 = analogRead(PIN_LM35_2);
  float milliVolt_2 = adcVal_2 * (ADC_VREF_mV / ADC_RESOLUTION);
  float tempC_2 = milliVolt_2 / 10;

  Serial.print(tempC);
  Serial.print(",");
  Serial.println(tempC_2);


  delay(100);
}
