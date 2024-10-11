/**
 * @file leds.h
 * @author Edilberto Carvajal
 * @date 11/10/2024
 *
 * @brief Archivo de cabecera biblioteca leds
 */

#ifndef LEDS_H
#define LEDS_H

#include <stdbool.h>
#include <stdint.h>

#define ALL_LED_OFF 0x0000
#define ALL_LED_ON  0xFFFF

/**
 * @brief Inicializa el puerto y apaga todos los LEDs
 *
 * @param direccion
 * @return true
 * @return false
 */
bool CrearLeds(uint16_t * direccion);

/**
 * @brief Enciende un LED
 *
 * @param led
 * @return true
 * @return false
 */
bool EncenderLeds(int led);

/**
 * @brief apaga un LED
 *
 * @param led
 * @return true
 * @return false
 */
bool ApagarLeds(int led);

/**
 * @brief Enciende todos los LEDs
 *
 */
void EncenderTodosLosLeds(void);

/**
 * @brief Apaga todos los LEDs
 *
 */
void ApagarTodosLosLeds(void);

/**
 * @brief Consulta si un LED está prendido
 *
 * @param led
 * @return true
 * @return false
 */
bool EstaElLedEncendido(int led);

#endif // LEDS_H
