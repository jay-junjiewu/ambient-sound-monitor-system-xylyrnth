#include "Xylyrnth_Bluetooth_master.h"

void Bt_Status(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if (event == ESP_SPP_SRV_OPEN_EVT) {
    Serial.println("Master Connected");
    master_connected = true;
  } else if (event == ESP_SPP_CLOSE_EVT) {
    Serial.println("Master Disconnected");
    master_connected = false;
  }
}

void bluetoothTask(void *parameter) {
  char line_buffer[MAX_LINE_LENGTH];
  int bufferIndex = 0;
  // Infinite loop running in parallel with loop() to receive Bluetooth messages
  while (true) {
    if (motor_duration != previous_motor_duration || frequency_threshold != previous_frequency_threshold || noise_level_threshold != previous_noise_level_threshold || haptic_toggle != previous_haptic_toggle) {
      snprintf(information_string, MAX_LINE_LENGTH, "%d,%d,%d,%d", motor_duration, frequency_threshold, noise_level_threshold, haptic_toggle);
      SerialBT.println(information_string);
      previous_motor_duration = motor_duration;
      previous_frequency_threshold = frequency_threshold;
      previous_noise_level_threshold = noise_level_threshold;
      previous_haptic_toggle = haptic_toggle;
    }
    while (SerialBT.available()) {
      received_string = SerialBT.readStringUntil('\n');
      int first_comma_index = received_string.indexOf(',');
      int second_comma_index = received_string.indexOf(',', first_comma_index + 1);
      String major_frequency_string = received_string.substring(0, first_comma_index);
      String volume_dB_string = received_string.substring(first_comma_index + 1, second_comma_index);
      major_frequency = major_frequency_string.toDouble();
      volume_dB = volume_dB_string.toDouble();
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);  // Yield to the watchdog periodically
  }
}
