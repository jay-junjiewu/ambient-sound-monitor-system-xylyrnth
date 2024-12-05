#include "Xylyrnth_Bluetooth_master.h"

void slave_connect() {
  Serial.println("Function BT connection executed");
  Serial.printf("Connecting to slave BT device named \"%s\" and MAC address \"%s\" is started.\n", slaveName.c_str(), MACadd.c_str());
  SerialBT.connect(address);
}

void Bt_Status(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if (event == ESP_SPP_OPEN_EVT) {
    Serial.println("Client Connected");
    SlaveConnected = true;
    recatt = 0;
  } else if (event == ESP_SPP_CLOSE_EVT) {
    Serial.println("Client Disconnected");
    SlaveConnected = false;
  }
}

void bluetoothTask(void *parameter) {
  slave_connect();
  char lineBuffer[MAX_LINE_LENGTH];
  int bufferIndex = 0;

  while (!SlaveConnected) {
    if (millis() - previousMillisReconnect >= 10000) {  // Connect every 10 seconds
      previousMillisReconnect = millis();
      recatt++;
      Serial.print("Trying to reconnect. Attempt No.: ");
      Serial.println(recatt);
      Serial.println("Stopping Bluetooth...");
      SerialBT.end();
      Serial.println("Bluetooth stopped !");
      Serial.println("Starting Bluetooth...");
      SerialBT.begin(myName, true);
      Serial.printf("The device \"%s\" started in master mode, make sure slave BT device is on!\n", myName.c_str());
      slave_connect();
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);  // Yield to the watchdog periodically
  }

  // Infinite loop running in parallel with loop() to receive Bluetooth messages
  while (true) {
    while (SerialBT.available()) {
      // Extract data from String
      received_string = SerialBT.readStringUntil('\n');
      // Find commas
      int firstCommaIndex = received_string.indexOf(',');
      int secondCommaIndex = received_string.indexOf(',', firstCommaIndex + 1);
      int thirdCommaIndex = received_string.indexOf(',', secondCommaIndex + 1);

      String motor_duration_string = received_string.substring(0, firstCommaIndex);
      String frequency_threshold_string = received_string.substring(firstCommaIndex + 1, secondCommaIndex);
      String noise_level_threshold_string = received_string.substring(secondCommaIndex + 1, thirdCommaIndex);
      String haptic_toggle_string = received_string.substring(thirdCommaIndex + 1);

      motor_duration = motor_duration_string.toInt();
      frequency_threshold = frequency_threshold_string.toInt();
      noise_level_threshold = noise_level_threshold_string.toInt();
      haptic_toggle = haptic_toggle_string.toInt();
    }

    vTaskDelay(10 / portTICK_PERIOD_MS);  // Yield to the watchdog periodically
  }
}

void bluetooth_setup(void) {
  SerialBT.register_callback(Bt_Status);
  
  // Start bluetooth device as master
  SerialBT.begin(myName, true);
  Serial.printf("The device \"%s\" started in master mode, make sure slave BT device is on!\n", myName.c_str());
  
  // Create FreeRTOS task
  xTaskCreatePinnedToCore(
    bluetoothTask,    // Function to implement the task
    "BluetoothTask",  // Name of the task
    10000,            // Stack size in words
    NULL,             // Task input parameter
    1,                // Priority of the task (highest priority)
    NULL,             // Task handle
    0                 // Core where the task should run
  );
}
