// 816030907
// Lab 2 Q2
#include "Lab2_Q2.h"  // Include custom header file for RTC functions

// I2C configuration structure
i2c_config_t pinconfig = {
    // Installing I2C driver in master mode
    .mode = I2C_MODE_MASTER,

    // Disabling pull-up resistors
    .sda_pullup_en = GPIO_PULLUP_DISABLE,
    .scl_pullup_en = GPIO_PULLUP_DISABLE,

    // Setting GPIO pins for SCL and SDA
    .scl_io_num = GPIO_NUM_0,
    .sda_io_num = GPIO_NUM_2,

    // Clock stretch tick duration
    .clk_stretch_tick = 1000
};

// Time structure for initializing RTC
struct tm Time = {
    .tm_year = 116,  // Year since 1900 (2016 - 1900)
    .tm_mon = 9,    // Month (0-based, September)
    .tm_mday = 9,    // Day of the month
    .tm_hour = 13,   // Hour in 24-hour format
    .tm_min = 50,   // Minutes
    .tm_sec = 10    // Seconds
};


int init_RTC() {
    i2cdev_init();  // Initialize I2C device

    printf("Hello WORL!\n");

    i2c_dev_t dev;  // I2C device structure
    memset(&dev, 0, sizeof(i2c_dev_t)); // Clear the structure
    dev.addr = DS3231_ADDR;  // Set the device address
    dev.cfg = pinconfig;     // Assign I2C configuration
    dev.port = I2C_NUM_0;    // Set the I2C port

    // Initialize DS3231 device descriptor
    ds3231_init_desc(&dev, 0, GPIO_NUM_2, GPIO_NUM_0);
    printf("55!\n");

    return 0;  // Return success
}


void reset_time_for_RTC() {
    i2cdev_init();  // Initialize I2C device

    i2c_dev_t dev2; // Another I2C device structure
    memset(&dev2, 0, sizeof(i2c_dev_t)); // Clear the structure
    dev2.addr = DS3231_ADDR; // Set the device address
    dev2.cfg = pinconfig;    // Assign I2C configuration
    dev2.port = I2C_NUM_0;   // Set the I2C port

    // Initialize DS3231 device descriptor
    if (ds3231_init_desc(&dev2, 0, GPIO_NUM_2, GPIO_NUM_0) == ESP_OK) {
        printf("work\n");
    }
    else {
        printf("not working\n");
    }

    printf("Here\n");

    // Set the time on the RTC
    if (ds3231_set_time(&dev2, &Time) == ESP_OK) {
        printf("Timeset\n");
    }
    else {
        printf("Error\n");
    }

    printf("Here 2\n");
}


void Read_time_from_RTC() {
    i2c_dev_t dev2; // I2C device structure for reading
    memset(&dev2, 0, sizeof(i2c_dev_t)); // Clear the structure
    dev2.addr = DS3231_ADDR; // Set the device address
    dev2.cfg = pinconfig;    // Assign I2C configuration
    dev2.port = I2C_NUM_0;   // Set the I2C port

    // Initialize DS3231 device descriptor
    if (ds3231_init_desc(&dev2, 0, GPIO_NUM_2, GPIO_NUM_0) == ESP_OK) {
        printf("work\n");
    }
    else {
        printf("not working\n");
    }

    printf("Here\n");

    struct tm time; // Time structure to hold the read time
    // Get the time from the RTC
    if (ds3231_get_time(&dev2, &time) == ESP_OK) {
        printf("Year: %d\n", time.tm_year + 1900); // Adjust year
        printf("Month: %d\n", time.tm_mon + 1);     // Adjust month
        printf("Day: %d\n", time.tm_mday);
        printf("Hour: %d\n", time.tm_hour);
        printf("Minute: %d\n", time.tm_min);
        printf("Second: %d\n", time.tm_sec);
    }
}

