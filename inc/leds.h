#ifndef LEDS_H
#define LEDS_H

#include <stdbool.h>
#include <stdint.h>

#define ALL_LED_OFF 0x0000
#define ALL_LED_ON  0xFFFF

bool CrearLeds(uint16_t * direccion);

bool EncenderLeds(int led);

bool ApagarLeds(int led);

void EncenderTodosLosLeds(void);

void ApagarTodosLosLeds(void);

bool EstaElLedEncendido(int led);

bool EstaElLedApagado(int led);

#endif // LEDS_H
