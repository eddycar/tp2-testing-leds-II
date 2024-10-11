/**
 * @file leds.h
 * @author Edilberto Carvajal
 * @date 11/10/2024
 *
 * @brief Archivo de implementación de biblioteca leds
 */

#include "leds.h"
#include "stddef.h"

#define LBS         0x0001
#define LED_OFFSET  1

/**
 * @brief Si está en modo DEBUG hace los chequeos
 *
 */
#ifdef DEBUG
#define ASSERT(arg)
if (arg) {
    while (1)
        ;
}
#else
#define ASSERT(arg) ;
#endif

#define FIRST_LED 1
#define LAST_LED  16

static uint16_t * puerto;

/**
 * @brief Comprueba que el valor de led este dentro de los limites
 *
 * @param led
 * @return true
 * @return false
 */
static bool ComprobarLimites(int led) {
    return ((FIRST_LED <= led) && (LAST_LED >= led));
}

/**
 * @brief Mascara de bits para led
 *
 * @param led
 * @return uint16_t
 */
uint16_t LedToMask(int led) {
    return LBS << (led - LED_OFFSET);
}

/**
 * @brief Inicializa el puerto y apaga todos los LEDs
 *
 * @param direccion
 * @return true
 * @return false
 */
bool CrearLeds(uint16_t * direccion) {
    if (NULL != direccion) {
        puerto = direccion;
        ApagarTodosLosLeds();
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Enciende un LED
 *
 * @param led
 * @return true
 * @return false
 */
bool EncenderLeds(int led) {
    if (false != ComprobarLimites(led)) {
        *puerto |= LedToMask(led);
        return true;
    } else {
        return false;
    }
}

/**
 * @brief apaga un LED
 *
 * @param led
 * @return true
 * @return false
 */
bool ApagarLeds(int led) {
    if (false != ComprobarLimites(led)) {
        *puerto &= ~LedToMask(led);
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Enciende todos los LEDs
 *
 */
void EncenderTodosLosLeds(void) {
    ASSERT(NULL != Puerto);
    *puerto = ALL_LED_ON;
}

/**
 * @brief Apaga todos los LEDs
 *
 */
void ApagarTodosLosLeds(void) {
    ASSERT(NULL != Puerto);
    *puerto = ALL_LED_OFF;
}

/**
 * @brief Consulta si un LED está prendido
 *
 * @param led
 * @return true
 * @return false
 */
bool EstaElLedEncendido(int led){
    ASSERT(NULL != puerto);
    return (*puerto & LedToMask(led)) != 0; 
}

