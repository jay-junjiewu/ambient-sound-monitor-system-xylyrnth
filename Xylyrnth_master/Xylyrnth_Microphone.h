#include <Arduino.h>
#include <driver/i2s.h>
#include <arduinoFFT.h>

// I2S Microphone
#define I2S_WS 25
#define I2S_SD 33
#define I2S_SCK 32
#define I2S_PORT I2S_NUM_0
#define SAMPLE_RATE 44100
#define BUFFER_LEN 1024
#define MAX_LINE_LENGTH 256

// FFT
int32_t i2s_read_buff[BUFFER_LEN];  // Store raw audio data
double vReal[BUFFER_LEN];           // Store real part of FFT
double vImag[BUFFER_LEN];           // Store imaginary part of FFT
double major_frequency = 0;         // Major frequency detected
double volume_dB = 0;               // Volume detected

ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, BUFFER_LEN, SAMPLE_RATE);

// Thresholds
int frequency_threshold = 2; // In kHz
int noise_level_threshold = 40; // In dB

unsigned long previousMillis = 0;  // For non-blocking delay

// Sets up the I2S interface
esp_err_t i2s_install();

// Assigns the I2S pins
esp_err_t i2s_setpin();

// Sets up the microphone using I2S
void microphone_setup(void);

// Sets the  major_frequency and volume_dB varibles with captured audio
void set_detected_frequency_volume(void);
