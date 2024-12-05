#include "Xylyrnth_Microphone.h"

esp_err_t i2s_install() {
  const i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = 0,  // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = BUFFER_LEN,
    .use_apll = false
  };
  return i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
}

esp_err_t i2s_setpin() {
  const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = -1,
    .data_in_num = I2S_SD
  };
  return i2s_set_pin(I2S_PORT, &pin_config);
}

void microphone_setup(void) {
  i2s_install();
  i2s_setpin();
  i2s_start(I2S_PORT);
}

void set_detected_frequency_volume(void) {
  size_t bytes_read = 0;
  esp_err_t result = i2s_read(I2S_PORT, (void *)i2s_read_buff, sizeof(i2s_read_buff), &bytes_read, 100 / portTICK_PERIOD_MS);
  if (result == ESP_OK && bytes_read > 0) {
    int samples_read = bytes_read / sizeof(int32_t);
    double sum_of_squares = 0.0;
    for (int i = 0; i < samples_read; i++) {
      int32_t raw_sample = i2s_read_buff[i];
      int16_t sample = raw_sample >> 16;  // Convert to 16-bit
      vReal[i] = (double)sample;          // Copy to FFT real part array
      vImag[i] = 0.0;                     // Initialize imaginary part to zero
      sum_of_squares += sample * sample;  // Accumulate the sum of squares
      if (i % 100 == 0) {
        vTaskDelay(1);  // Yield to the watchdog periodically
      }
    }

    // Perform FFT
    FFT.windowing(vReal, BUFFER_LEN, FFT_WIN_TYP_HAMMING, FFT_FORWARD);  // Windowing
    FFT.compute(vReal, vImag, BUFFER_LEN, FFT_FORWARD);                  // Compute FFT
    major_frequency = FFT.majorPeak();

    double rms = sqrt(sum_of_squares / samples_read);  // Calculate RMS
    volume_dB = 20 * log10(rms);                       // RMS to dB
  }
}
