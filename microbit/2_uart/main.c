#include "uart.h"
#include "gpio.h"
#include <stdio.h>


#define __BUTTON_A_PIN__ 14
#define __BUTTON_B_PIN__ 23

/*
ssize_t _write(int fd, const void *buf, size_t count){
char * letter = (char *)(buf);
for(int i = 0; i < count; i++){
uart_send(*letter);
letter++;
}
return count;
}
*/

int main() {

    uart_init();
    gpio_init();
    GPIO0->PIN_CNF[__BUTTON_A_PIN__] = 0; // button A 
	GPIO0->PIN_CNF[__BUTTON_B_PIN__] = 0; // button B
    GPIO0->PIN_CNF[21] = 1; //Row 1
    GPIO0->PIN_CNF[28] = 1; //Col 1
	GPIO0->PIN_CNF[11] = 1; //Col 2
	GPIO0->PIN_CNF[31] = 1; //Col 3
	GPIO1->PIN_CNF[5] = 1;  //Col 4
	GPIO0->PIN_CNF[30] = 1; //Col 5 
 
    while (1) {
       // iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
        if (!(GPIO0->IN & (1<<__BUTTON_A_PIN__))) {
            uart_send('A');
            gpio_lights_off();

        }
        if (!(GPIO0->IN & (1<<__BUTTON_B_PIN__))) {
            uart_send('B');
            gpio_lights_on();
        }


        if(uart_read() != 'E'){
            if (GPIO0->OUT & (1<< 21)){

                gpio_lights_off();
            }
            else
            {
                gpio_lights_on();
            }

        }

    }
    return 0;
}