#include "inc/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




static uint16_t puerto_virtual;





void setUp(void) {

    CrearLeds(&puerto_virtual);

}





void tearDown(void) {

}





void test_todos_los_leds_inician_apagados(void) {

    uint16_t puerto_virtual = 0xFFFF;

    do {if ((CrearLeds(&puerto_virtual))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(19)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_un_led_individual(void) {

    do {if ((EncenderLeds(7))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(25)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 6)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_un_led_individual(void) {

    do {if ((EncenderLeds(3))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(31)));}} while(0);

    do {if ((ApagarLeds(3))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(32)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_multiples_leds(void) {

    do {if ((EncenderLeds(7))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(38)));}} while(0);

    do {if ((EncenderLeds(5))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(39)));}} while(0);

    do {if ((ApagarLeds(2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(40)));}} while(0);

    do {if ((ApagarLeds(7))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(41)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_todos_los_leds_simultaneamente(void) {

    EncenderTodosLosLeds();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todos_los_leds_simultaneamente(void) {

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_HEX16);

}





void test_consultar_estado_cuando_led_encendido(void) {

    do {if ((EncenderLeds(15))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

    do {if ((EstaElLedEncendido(15))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(59)));}} while(0);

}





void test_consultar_estado_cuando_led_apagado(void) {

    do {if (!(EstaElLedEncendido(15))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(64)));}} while(0);

}





void test_puerto_nulo(void) {

    uint16_t puerto_virtual_nulo = 

                                  ((void *)0)

                                      ;

    do {if (!(CrearLeds(puerto_virtual_nulo))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(70)));}} while(0);

}





void test_limite_de_parametros(void) {

    do {if ((EncenderLeds(2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(75)));}} while(0);

    do {if ((EncenderLeds(8))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(76)));}} while(0);

    do {if ((EncenderLeds(16))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(77)));}} while(0);



    do {if ((ApagarLeds(1))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(79)));}} while(0);

    do {if ((ApagarLeds(8))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(80)));}} while(0);

    do {if ((ApagarLeds(16))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(81)));}} while(0);

}





void test_parametros_fuera_de_limites(void) {

    do {if (!(EncenderLeds(-1))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(86)));}} while(0);

    do {if (!(EncenderLeds(0))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(87)));}} while(0);

    do {if (!(EncenderLeds(18))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(88)));}} while(0);



    do {if (!(ApagarLeds(-2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(90)));}} while(0);

    do {if (!(ApagarLeds(0))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(91)));}} while(0);

    do {if (!(ApagarLeds(20))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(92)));}} while(0);

}
