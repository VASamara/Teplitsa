#pragma once
#include <Arduino.h>
#include <DS3231.h>
#include <AHT10.h>
#include <menu.h>
#include <EncButton.h>
#include <LiquidCrystal_I2C.h>
#include <PCF8574.h>
#include <EEPROM.h>
#include <elapsedMillis.h>

#define SW 0        // Кнопка энкодера  pin D0
#define POMP 1      // Насос для полива pin D1
#define DT 2        // Сигнал энкодера
#define CLK 3       // Сигнал энкодера
#define WCNTR 4     // Счетчик расхода воды
#define HEAT 5      // Подогрев пола в рассаднике
#define DRIVER 6    // Привод окна в теплице
#define DALLAS_1 7  // Датчик температуры подогрева пола в рвссаднике
#define DALLAS_2 8  // Датчики температуры грунта
#define LIGHT 9     // Освещение в рассаднике
#define SS 10       // Шина SPI
#define MOSI 11     // Шина SPI
#define MISO 12     // Шина SPI
#define SCK 13      // Шина SPI
#define SENS_0 A0   // Датчик влажности грунта
#define SENS_VCC A1 // Питание датчиков влажности грунта
#define SENS_1 A2   // Датчик влажности грунта
#define SENS_2 A3   // Датчик влажности грунта
#define SDA A4      // Шина I2C
#define SCL A5      // Шина I2C
#define SENS_3 A6   // Датчик влажности грунта
#define SENS_4 A7   // Датчик влажности грунта
