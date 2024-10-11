#include "leds.h"
#include "stddef.h"

#define LBS         0x0001
#define LED_OFFSET  1

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

static bool ComprobarLimites(int led) {
    return ((FIRST_LED <= led) && (LAST_LED >= led));
}

uint16_t LedToMask(int led) {
    return LBS << (led - LED_OFFSET);
}

bool CrearLeds(uint16_t * direccion) {
    if (NULL != direccion) {
        puerto = direccion;
        ApagarTodosLosLeds();
        return true;
    } else {
        return false;
    }
}

bool EncenderLeds(int led) {
    if (false != ComprobarLimites(led)) {
        *puerto |= LedToMask(led);
        return true;
    } else {
        return false;
    }
}

bool ApagarLeds(int led) {
    if (false != ComprobarLimites(led)) {
        *puerto &= ~LedToMask(led);
        return true;
    } else {
        return false;
    }
}

void EncenderTodosLosLeds(void) {
    ASSERT(NULL != Puerto);
    *puerto = ALL_LED_ON;
}

void ApagarTodosLosLeds(void) {
    ASSERT(NULL != Puerto);
    *puerto = ALL_LED_OFF;
}

bool EstaElLedEncendido(int led){
    ASSERT(NULL != puerto);
    return (*puerto & LedToMask(led)) != 0; 
}

