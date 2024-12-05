#include "BluetoothSerial.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

// Bluetooth
unsigned long previousMillisReconnect;  // Compare millis counter for the reconnection timer
bool SlaveConnected = false;
int recatt = 0;  // Count reconnection attempts
String myName = "ESP32-Master";
String slaveName = "ESP32-Slave";
String MACadd = "10:06:1C:E5:95:0E";    // Slave MAC address for printing
uint8_t address[6] = { 0x10, 0x06, 0x1C, 0xE5, 0x95, 0x0E };  // Slave Mac address for connection

BluetoothSerial SerialBT;     // Bluetooth Serial object
String received_string = "";  // String to store received data

// Connects to slave bluetooth device
void slave_connect();

// Bluetooth Status callback function
void Bt_Status(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);

// FreeRTOS Bluetooth task running on core 0
void bluetoothTask(void *parameter);

// Sets up the Bluetooth Communication
void bluetooth_setup(void);
