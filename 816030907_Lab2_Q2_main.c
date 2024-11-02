// 816030907
// Lab 2 Q2
#include <stdio.h>                 // Standard input/output library
#include <ctype.h>                 // Character handling library
#include <stdlib.h>                // Standard library for memory allocation
#include <string.h>                // String handling functions
#include <unistd.h>                // Unix standard functions
#include "freertos/FreeRTOS.h"     // FreeRTOS API
#include "freertos/task.h"         // Task management
#include "freertos/queue.h"        // Queue management
#include "esp_sleep.h"             // ESP32 sleep modes
#include "driver/gpio.h"           // GPIO control
#include "driver/hw_timer.h"       // Hardware timer functions
#include "driver/uart.h"           // UART communication
#include "driver/i2c.h"            // I2C communication
#include "freertos/semphr.h"       // Semaphore support
#include "freertos/FreeRTOSConfig.h" // FreeRTOS configuration
#include "ds3231.h"                // DS3231 RTC driver
#include <i2cdev.h>                // I2C device handling
#include "Lab2_Q2.h"               // Project-specific header


void app_main() {
    // Print identification information
    printf("Damanie Jangbahadoorsingh!\n");
    printf("816030907!\n");

    // Initialize the RTC (Real-Time Clock)
    init_RTC();

    // Reset time for the RTC
    reset_time_for_RTC();

    // Main loop
    while (1) {
        // Read time from RTC
        Read_time_from_RTC();

        // Delay for half a second
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

