# ambient-sound-monitor-system-xylyrnth

**Xylyrnth** is an intelligent ambient sound monitoring system designed for the smartwatch market, targeting users who may struggle to stay aware of their surroundings or frequently operate in noisy environments. The system leverages advanced real-time processing to detect key sounds and deliver alerts through haptic and visual feedback.  

## System Overview  

Xylyrnth is built around two custom ESP32 hardware boards, programmed entirely in low-level embedded C to ensure optimal performance and precise control. These boards communicate via Bluetooth and perform tightly synchronized tasks:  

### The Bracelet (Master)  
- Captures real-time audio data through an integrated microphone.  
- Implements Fast Fourier Transform (FFT) and additional digital signal processing techniques to analyze and identify key sounds in real-time.  
- Provides immediate alerts through haptic feedback, offering an intuitive way for users to stay informed of critical sounds.  

### The Display (Slave)  
- Offers an intuitive interface for users to configure which sounds are detected and how alerts are delivered.  
- Operates an LCD display controlled in real time, displaying user settings and system information dynamically.  

## Technical Details  

The firmware is structured around **FreeRTOS**, enabling parallel processing across multiple real-time tasks, including:  
- Acquiring audio data.  
- Performing real-time DSP.  
- Managing Bluetooth communication.  
- Updating the LCD display seamlessly.  

By using low-level embedded C programming, Xylyrnth achieves precise control over hardware resources, ensuring efficient and reliable performance for all system functions. This design highlights the system’s ability to tackle complex, real-time operations within the constraints of embedded systems.  

## Operating Principle  

The system architecture and operation are illustrated below:  

*(Include your diagram here, e.g., by adding an image file to your repository and linking it)*  


![System Diagram](operating_flowchart.png)

## Note

This repository is provided as an archive for the Xylyrnth project and will not undergo further development or updates. The system was specifically designed to function with two custom ESP32 hardware PCB boards, which I developed. Due to the tailored nature of these hardware components and their integration within the system, it is not suitable for general-purpose use or adaptation. This repository is shared primarily as a reference for those interested in the project’s design and implementation.

