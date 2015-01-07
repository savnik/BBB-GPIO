#include <stdio.h>
#include <stdlib.h>

//#include <iostream.h>
#include <string.h>
#include <unistd.h>
#include "gpio.h"


unsigned int LEDGPIO = 60;   // GPIO1_28 = (1x32) + 28 = 60
unsigned int ButtonGPIO = 15;   // GPIO0_15 = (0x32) + 15 = 15

int main(int argc, char *argv[]){
	int i;
	printf("Testing the GPIO Pins\n");

        gpio_export(LEDGPIO);    // The LED
	gpio_export(ButtonGPIO);   // The push button switch
        gpio_set_dir(LEDGPIO, OUTPUT_PIN);   // The LED is an output
	gpio_set_dir(ButtonGPIO, INPUT_PIN);   // The push button input
	
	// Flash the LED 5 times
	for(i=0; i<5; i++){
		printf("Setting the LED on\n");
                gpio_set_value(LEDGPIO, HIGH);
		usleep(200000);         // on for 200ms
		printf("Setting the LED off\n");
                gpio_set_value(LEDGPIO, LOW);
		usleep(200000);         // off for 200ms
	}

	// Wait for the push button to be pressed
	printf("Please press the button!\n");

	unsigned int value = LOW;
	do {
		gpio_get_value(ButtonGPIO, &value); 
		printf(".");
		usleep(1000);      // sleep for one millisecond
	} while (value!=HIGH);
	printf("\nButton was just pressed!\n");

	printf("Finished Testing the GPIO Pins\n");
	gpio_unexport(LEDGPIO);     // unexport the LED
	gpio_unexport(ButtonGPIO);  // unexport the push button
	return 0;
}
