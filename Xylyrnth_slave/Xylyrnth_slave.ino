/*****************************************************************************************
*    Xylyrnth as a Slave: Bluetooth, LCD Touchscreen
******************************************************************************************/

#include "Xylyrnth_GSLC.h"
#include "Xylyrnth_Bluetooth_slave.h"

void setup() {
  Serial.begin(9600);

  gslc_InitDebug(&DebugOut);

  // Create graphic elements
  InitGUIslice_gen();
  m_gui.nFlipX = !m_gui.nFlipX;

  // Setup Bluetooth for communication with master
  SerialBT.register_callback(Bt_Status);
  SerialBT.begin(device_name);
  Serial.printf("\"%s\" with MAC address \"%s\" is started.\n", device_name.c_str(), MACadd.c_str());

  // Create a task to handle Bluetooth communication
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

void loop() {
  // Update GUI Elements
  if (millis() - previous_refresh > GUI_REFRESH_INTERVAL) {
    snprintf(gui_text_display, MAX_STR, "%.2f", major_frequency);
    gslc_ElemSetTxtStr(&m_gui, m_pElemOutTxtFreq, gui_text_display);
    gslc_ElemXRingGaugeSetVal(&m_gui, m_pElemXRingGauge2, major_frequency);

    noise_level_threshold = gslc_ElemXSliderGetPos(&m_gui, m_pSliderThreshold);
    snprintf(gui_text_display, MAX_STR, "%d", noise_level_threshold);
    gslc_ElemSetTxtStr(&m_gui, m_pThreshold, gui_text_display);

    frequency_threshold = gslc_ElemXSliderGetPos(&m_gui, m_pSliderFrequency);
    snprintf(gui_text_display, MAX_STR, "%d", frequency_threshold);
    gslc_ElemSetTxtStr(&m_gui, m_pFrequency, gui_text_display);

    motor_duration = gslc_ElemXSliderGetPos(&m_gui, m_pSliderHaptics);
    snprintf(gui_text_display, MAX_STR, "%d", motor_duration);
    gslc_ElemSetTxtStr(&m_gui, m_pHapticDuration, gui_text_display);

    if (major_frequency > frequency_threshold * 1000 && volume_dB > noise_level_threshold) {
      snprintf(gui_text_display, MAX_STR, "ALERT");
      gslc_ElemSetTxtStr(&m_gui, m_pElemAlertTxt, gui_text_display);
      int previous_alert = millis();
    } else {
      snprintf(gui_text_display, MAX_STR, " ");
      gslc_ElemSetTxtStr(&m_gui, m_pElemAlertTxt, gui_text_display);
    }

    // Periodically call GUIslice update function
    gslc_Update(&m_gui);
  }

  vTaskDelay(100 / portTICK_PERIOD_MS);  // Yield to the watchdog periodically
}
