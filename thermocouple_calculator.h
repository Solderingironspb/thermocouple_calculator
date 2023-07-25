/**
 ******************************************************************************
 *  @file thermocouple_calculator.h
 *  @brief Калькулятор: Термопары (ГОСТ Р 8.85-2001)
 *  @author Волков Олег
 *  @date 24.07.2023
 ******************************************************************************
 * @attention
 *
 * Расчеты ведутся согласно ГОСТ Р 8.85-2001
 * Поддерживаются следующие термопары:
 *  - R ТПП (Платина - 13% родий/платина)
 *  - S ТПП (Платина - 10% родий/платина)
 *  - B ТПР (Платина - 30% родий/платина - 6% родий)
 *  - J ТЖК [Железо/медь - никель (железо/константан)]
 *  - T ТМК [Медь/медь - никель (медь/константан)]
 *  - E ТХКн [Никель - хром/медь - никель (хромель/константан)]
 *  - K ТХА [Никель - хром/никель - алюминий (хромель/алюмель)]
 *  - N ТНН [Никель - хром - кремний/никель - кремний (нихросил/нисил)]
 *  - A(A-1, A-2, A-3) ТВР (Вольфрам - рений/вольфрам - рений)
 *  - L ТХК (Хромель/копель)
 *  - M ТМК (Медь/копель)
 *
 * Разрешение:
 *  - R: от -50 °C до 1768.1 °C
 *  - S: от -50 °C до 1768.1 °C
 *  - B: от 0 °C до 1820 °C
 *  - J: от -210 °C до 1200 °C
 *  - T: от -270 °C до 400 °C
 *  - E: от -270 °C до 1000 °C
 *  - K: от -270 °C до 1372 °C
 *  - N: от -270 °C до 1300 °C
 *  - A-1: от 0 °C до 2500 °C
 *  - A-2: от 0 °C до 1800 °C
 *  - A-3: от 0 °C до 1800 °C
 *  - L: от -200 °C до 800 °C
 *  - M: от -200 °C до 100 °C
 *
 * Диапазон ТЭДС:
 *  - R: от -0.225 мВ до 21.103 мВ (от -50 °C до 1768.1 °C)
 *  - S: от -0.235 мВ до 18.694 мВ (от -50 °C до 1768.1 °C)
 *  - B: от 0.291 мВ до 13.820 мВ (от 250 °C до 1820 °C)
 *  - J: от -8.095 мВ до 69.553 мВ (от -210 °C до 1200 °C)
 *  - T: от -5.603 мВ до 20.872 мВ (от -200 °C до 400 °C)
 *  - E: от -8.825 мВ до 76.373 мВ (от -200 °C до 1000 °C)
 *  - K: от -5.891 мВ до 54.886 мВ (от -200 °C до 1372 °C)
 *  - N: от -3.990 мВ до 47.513 мВ (от -200 °C до 1300 °C)
 *  - A-1: от 0 мВ до 33.640 мВ (от 0 °C до 2500 °C)
 *  - A-2: от 0 мВ до 27.232 мВ (от 0 °C до 1800 °C)
 *  - A-3: от 0 мВ до 26.773 мВ (от 0 °C до 1800 °C)
 *  - L: от -9.488 мВ до 66.466 мВ (от -200 °C до 800 °C)
 *  - M: от -6.154 мВ до 4.722 мВ (от -200 °C до 100 °C)
 *
 *  ГОСТ: https://docs.cntd.ru/document/1200028583
 *  GitHub: https://github.com/Solderingironspb
 *  Моя программа для ПК для расчета CRC-8, CRC-16, CRC-32 + мини-программы(Данный калькулятор там тоже есть):
 *  https://github.com/Solderingironspb/CRC-Calculator-by-Solderingiron/tree/main
 ******************************************************************************
 */

#include <stdint.h>
#include <math.h>

enum {
	Thermocouple_R,
	Thermocouple_S,
	Thermocouple_B,
	Thermocouple_J,
	Thermocouple_T,
	Thermocouple_E,
	Thermocouple_K,
	Thermocouple_N,
	Thermocouple_A1,
	Thermocouple_A2,
	Thermocouple_A3,
	Thermocouple_L,
	Thermocouple_M
};

double Thermocouple_temperature_to_TEMF_R(double Temperature);
double Thermocouple_TEMF_to_temperature_R(double TEMF);
double Thermocouple_temperature_to_TEMF_S(double Temperature);
double Thermocouple_TEMF_to_temperature_S(double TEMF);
double Thermocouple_temperature_to_TEMF_B(double Temperature);
double Thermocouple_TEMF_to_temperature_B(double TEMF);
double Thermocouple_temperature_to_TEMF_J(double Temperature);
double Thermocouple_TEMF_to_temperature_J(double TEMF);
double Thermocouple_temperature_to_TEMF_T(double Temperature);
double Thermocouple_TEMF_to_temperature_T(double TEMF);
double Thermocouple_temperature_to_TEMF_E(double Temperature);
double Thermocouple_TEMF_to_temperature_E(double TEMF);
double Thermocouple_temperature_to_TEMF_K(double Temperature);
double Thermocouple_TEMF_to_temperature_K(double TEMF);
double Thermocouple_temperature_to_TEMF_N(double Temperature);
double Thermocouple_TEMF_to_temperature_N(double TEMF);
double Thermocouple_temperature_to_TEMF_A1(double Temperature);
double Thermocouple_TEMF_to_temperature_A1(double TEMF);
double Thermocouple_temperature_to_TEMF_A2(double Temperature);
double Thermocouple_TEMF_to_temperature_A2(double TEMF);
double Thermocouple_temperature_to_TEMF_A3(double Temperature);
double Thermocouple_TEMF_to_temperature_A3(double TEMF);
double Thermocouple_temperature_to_TEMF_L(double Temperature);
double Thermocouple_TEMF_to_temperature_L(double TEMF);
double Thermocouple_temperature_to_TEMF_M(double Temperature);
double Thermocouple_TEMF_to_temperature_M(double TEMF);
void Thermocouple_hardfault(void);
double Thermocouple_Get_Temperature(double Temperature_cold_junior, double TEMF, uint8_t Type);


