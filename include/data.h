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
#include <Poliv.h>
#include <sun.h>
#include <heat.h>
#include <microDS18B20.h>

#define SW 0        //* Кнопка энкодера  pin D0                         // SW
#define WCNTR 1     // Счетчик расхода воды                            // RELAY_0
#define DT 2        //* Сигнал энкодера                                 // DT
#define CLK 3       //* Сигнал энкодера                                 // CLK
#define DALLAS_1 4  //* Датчик температуры подогрева пола в рвссаднике  // RELAY_1
#define HEAT 5      //* Подогрев пола в рассаднике                      // RELAY_2
#define DRV_PWM 6   //* Привод окна в теплице PWM                       // RELAY_3
#define DRV_SIG_1 7 //* Привод окна в теплице IN1                       // RELAY_4
#define DRV_SIG_2 8 //* Привод окна в теплице IN2                       // RELAY_5
#define LIGHT 9     //* Освещение в рассаднике                          // RELAY_6
//#define SS 10       // Шина SPI                                        // DRV_SIGNAL1 10
//#define MOSI 11     // Шина SPI                                        // DRV_PWM     11
//#define MISO 12     // Шина SPI                                        // DRV_SIGNAL2 12
//#define SCK 13      // Шина SPI                                        // SERVO_0   13
#define SENS_0 A0   // Датчик влажности грунта                         // SERVO_1   A0
#define SENS_VCC A1 // Питание датчиков влажности грунта               // SENS_VCC  A1
#define SENS_1 A2   // Датчик влажности грунта                         // SENS_1    A2
#define SENS_2 A3   // Датчик влажности грунта                         // SENS_2    A3
//#define SDA A4      // Шина I2C                                        //
//#define SCL A5      // Шина I2C                                        //
#define SENS_3 A6 // Датчик температуры грунта                       // SENS_3    A6
#define SENS_4 A7 // Датчик температуры грунта                       // SENS_4    A7

#define EE_SUNRISE_HOUR 0
#define EE_SUNRISE_MINUTE 1
#define EE_DURATION_SUN 2
#define EE_SUNSET_HOUR 3
#define EE_SUNSET_MINUTE 4

#define EE_TEMP_HEATING_DAY 5
#define EE_TEMP_HEATING_NIGHT 6
#define EE_HEATING_PWM 7

#define EE_TEMP_COOLING_OUT_OPEN 8
#define EE_TEMP_COOLING_OUT_CLOSE 9
#define EE_TEMP_COOLING_IN_OPEN 10
#define EE_TEMP_COOLING_IN_CLOSE 11
#define EE_COOLING_PWM 12
#define EE_COOLING_DRV_STOP_DELAY 13

#define EE_OPTION_ON 14

#define EE_SET_HOUR 15
#define EE_SET_MINUTE 16
#define EE_SET_WEEK_DAY 17

#define EE_VLV_1_SET_WEEK_DAYS 20
#define EE_VLV_1_SET_LONG 21

#define EE_VLV_2_SET_WEEK_DAYS 22
#define EE_VLV_2_SET_LONG 23

#define EE_VLV_3_SET_WEEK_DAYS 24
#define EE_VLV_3_SET_LONG 25

#define EE_VLV_4_SET_WEEK_DAYS 26
#define EE_VLV_4_SET_LONG 27

#define EE_VLV_5_SET_WEEK_DAYS 28
#define EE_VLV_5_SET_LONG 29

#define EE_VLV_6_SET_WEEK_DAYS 30
#define EE_VLV_6_SET_LONG 31

#define EE_VLV_7_SET_WEEK_DAYS 32
#define EE_VLV_7_SET_LONG 33
