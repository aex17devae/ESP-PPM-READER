#include <Arduino.h>

#define PPM_PIN 25      // Pin connected to the PPM signal
#define NUM_CHANNELS 6  // The number of PPM channels you expect
#define SYNC_GAP 3000   // Minimum pulse length in microseconds that signals a frame reset

volatile uint16_t ppmValues[NUM_CHANNELS] = { 0 };
volatile uint8_t currentChannel = 0;
volatile uint32_t lastTime = 0;

hw_timer_t* timer = NULL;  // Timer for accurate pulse width measurement
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onPPMInterrupt() {
  uint32_t now = micros();
  uint32_t duration = now - lastTime;
  lastTime = now;

  if (duration >= SYNC_GAP) {
    // Sync pulse detected, reset channel index
    currentChannel = 0;
  } else if (currentChannel < NUM_CHANNELS) {
    ppmValues[currentChannel] = duration;
    currentChannel++;
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(PPM_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(PPM_PIN), onPPMInterrupt, RISING);
}

void loop() {
  static uint32_t lastPrintTime = 0;
  uint32_t currentTime = millis();

  if (currentTime - lastPrintTime >= 100) {  // Print every 100 ms
    lastPrintTime = currentTime;

    portENTER_CRITICAL(&timerMux);  // Enter critical section
    Serial.print("PPM values: ");
    for (int i = 0; i < NUM_CHANNELS; i++) {
      Serial.print(ppmValues[i]);
      Serial.print(" ");
    }
    Serial.println();
    portEXIT_CRITICAL(&timerMux);  // Exit critical section
  }
}
