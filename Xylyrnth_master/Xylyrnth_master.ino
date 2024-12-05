/*****************************************************************************************
*    Xylyrnth as a Master: Microphone, Bluetooth, FFT, Motor
******************************************************************************************/

#include "Xylyrnth_Bluetooth_master.h"
#include "Xylyrnth_Microphone.h"

// Motor Variables
#define MOTOR_PIN 15
bool haptic_block = false;  // Used to block the motor
int motor_duration = 1;     // seconds
bool haptic_toggle = true;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);
  microphone_setup();
  bluetooth_setup();
}

void loop() {
  // Sets the  major_frequency and volume_dB varibles with captured audio
  set_detected_frequency_volume();

  // Generate haptic feedback as an alert if frequency or volume greater than threshold
  if (major_frequency > frequency_threshold * 1000 && haptic_block == 0 && haptic_toggle && volume_dB > noise_level_threshold) {
    digitalWrite(MOTOR_PIN, HIGH);
    previousMillis = millis();
    haptic_block = 1;
  }

  // Turns haptic feedback off using non-blocking delay
  if (millis() - previousMillis >= motor_duration * 1000) {
    digitalWrite(MOTOR_PIN, LOW);
  }

  // Remove the block on the motor to avoid motor noise triggering an alert
  if (millis() - previousMillis >= (motor_duration * 1000 + 350)) {
    haptic_block = 0;
  }

  // Sends the frequency and volume data as a string via bluetooth
  char major_frequency_string[MAX_LINE_LENGTH];
  snprintf(major_frequency_string, MAX_LINE_LENGTH, "%.2f,%.2f", major_frequency, volume_dB);
  SerialBT.println(major_frequency_string);

  vTaskDelay(10 / portTICK_PERIOD_MS);  // Yield to the watchdog periodically
}
