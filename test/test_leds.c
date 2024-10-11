
#include "unity.h"
#include "leds.h"

static uint16_t puerto_virtual;

// Se ejecuta antes de cada prueba
void setUp(void) {
    CrearLeds(&puerto_virtual);
}

// Se ejecuta despues de cada prueba
void tearDown(void) {
}

// Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;
    TEST_ASSERT_TRUE(CrearLeds(&puerto_virtual));
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prender un LED individual.
void test_prender_un_led_individual(void) {
    TEST_ASSERT_TRUE(EncenderLeds(7));
    TEST_ASSERT_EQUAL_HEX16(1 << 6, puerto_virtual);
}

// Apagar un LED individual.
void test_prender_y_apagar_un_led_individual(void) {
    TEST_ASSERT_TRUE(EncenderLeds(3));
    TEST_ASSERT_TRUE(ApagarLeds(3));
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prender y apagar múltiples LED’s.
void test_prender_y_apagar_multiples_leds(void) {
    TEST_ASSERT_TRUE(EncenderLeds(7));
    TEST_ASSERT_TRUE(EncenderLeds(5));
    TEST_ASSERT_TRUE(ApagarLeds(2));
    TEST_ASSERT_TRUE(ApagarLeds(7));
    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

// Prender todos los LEDs de una vez.
void test_prender_todos_los_leds_simultaneamente(void) {
    EncenderTodosLosLeds();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

// Apagar todos los LEDs de una vez.
void test_apagar_todos_los_leds_simultaneamente(void) {
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Consultar el estado de un LED cuando está encendido
void test_consultar_estado_cuando_led_encendido(void) {
    TEST_ASSERT_TRUE(EncenderLeds(15));
    TEST_ASSERT_TRUE(EstaElLedEncendido(15));
}

// Consultar el estado de un LED cuando está apagado
void test_consultar_estado_cuando_led_apagado(void) {
    TEST_ASSERT_FALSE(EstaElLedEncendido(15));
}

// Prueba de puerto nulo
void test_puerto_nulo(void) {
    uint16_t puerto_virtual_nulo = NULL;
    TEST_ASSERT_FALSE(CrearLeds(puerto_virtual_nulo));
}

// Revisar limites de los parametros.
void test_limite_de_parametros(void) {
    TEST_ASSERT_TRUE(EncenderLeds(2));
    TEST_ASSERT_TRUE(EncenderLeds(8));
    TEST_ASSERT_TRUE(EncenderLeds(16));

    TEST_ASSERT_TRUE(ApagarLeds(1));
    TEST_ASSERT_TRUE(ApagarLeds(8));
    TEST_ASSERT_TRUE(ApagarLeds(16));
}

// Revisar parámetros fuera de los limites.
void test_parametros_fuera_de_limites(void) {
    TEST_ASSERT_FALSE(EncenderLeds(-1));
    TEST_ASSERT_FALSE(EncenderLeds(0));
    TEST_ASSERT_FALSE(EncenderLeds(18));

    TEST_ASSERT_FALSE(ApagarLeds(-2));
    TEST_ASSERT_FALSE(ApagarLeds(0));
    TEST_ASSERT_FALSE(ApagarLeds(20));
}