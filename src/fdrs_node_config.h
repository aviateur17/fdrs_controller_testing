//  FARM DATA RELAY SYSTEM
//
//  Sensor Configuration

#include <fdrs_globals.h>

#define READING_ID    42   //Unique ID for this sensor
#define GTWY_MAC      0xef //Address of the nearest gateway

//#define USE_ESPNOW
#define USE_LORA
//#define DEEP_SLEEP
//#define POWER_CTRL    14
#define FDRS_DEBUG
#define DEBUG_CONFIG // Displays full config info on startup

// OLED -- Displays console debugging messages on an SSD1306 I²C OLED
#define USE_OLED    
#define OLED_HEADER "FDRS"
#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_RST 16

// LoRa Configuration
#define RADIOLIB_MODULE SX1276 //Tested on SX1276
//#define USE_SX126X
#define LORA_SS 26
#define LORA_RST 27
#define LORA_DIO 5

#define LORA_TXPWR 2    // LoRa TX power in dBm (: +2dBm - +17dBm (for SX1276-7) +20dBm (for SX1278))
#define LORA_ACK        // Request LoRa acknowledgment.

#define CUSTOM_SPI
#define LORA_SPI_SCK 18
#define LORA_SPI_MISO 19
#define LORA_SPI_MOSI 23