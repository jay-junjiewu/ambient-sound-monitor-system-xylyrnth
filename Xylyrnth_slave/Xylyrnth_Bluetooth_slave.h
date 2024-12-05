#include "BluetoothSerial.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define MAX_LINE_LENGTH 256

bool master_connected;
String device_name = "ESP32-BT-Slave";  // Slave name
String MACadd = "CC:DB:A7:33:F6:46";    // Slave Bluetooth Mac address

BluetoothSerial SerialBT;     // Bluetooth Serial object
String received_string = "";  // String to store received data

int motor_duration = 1;
int previous_motor_duration = 0;
int frequency_threshold = 2;
int previous_frequency_threshold = 0;
int noise_level_threshold = 40;
int previous_noise_level_threshold = 0;
bool haptic_toggle = true;
bool previous_haptic_toggle = false;
char information_string[MAX_LINE_LENGTH];
double major_frequency = 0;  // Major frequency detected
double volume_dB = 0;        // Maximum volumne detected

// Bluetooth Status callback function
void Bt_Status(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);

// FreeRTOS Bluetooth task running on core 0
void bluetoothTask(void *parameter);