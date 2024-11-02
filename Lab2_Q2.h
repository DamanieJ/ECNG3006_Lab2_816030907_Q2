// 816030907
// Header file inclusion and function declarations for RTC operations

#include <stdio.h>                       // Standard input/output functions
#include <ctype.h>                      // Character handling functions
#include <stdlib.h>                     // Standard library for memory allocation
#include <string.h>                     // String manipulation functions
#include <unistd.h>                     // Unix standard functions
#include "freertos/FreeRTOS.h"         // FreeRTOS API header
#include "freertos/task.h"              // FreeRTOS task management
#include "freertos/queue.h"             // FreeRTOS queue management
#include "esp_sleep.h"                  // ESP32 sleep modes header
#include "driver/gpio.h"                // GPIO driver header
#include "driver/hw_timer.h"            // Hardware timer functions
#include "driver/uart.h"                // UART driver header
#include "driver/i2c.h"                 // I2C driver header
#include "freertos/semphr.h"             // FreeRTOS semaphore support
#include "freertos/FreeRTOSConfig.h"    // FreeRTOS configuration
#include "ds3231.h"                     // DS3231 RTC driver header
#include <i2cdev.h>                     // I2C device handling library

// Prevent multiple inclusions of this header file
#ifndef NVS_LAB2_H
#define NVS_LAB2_H


 
int init_RTC();


void reset_time_for_RTC();


void Read_time_from_RTC();

#endif // NVS_LAB2_H


