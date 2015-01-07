#include <stdio.h>
#include <stdlib.h>

//#include <iostream.h>
#include <string.h>
#include <unistd.h>
#include "gpio.h"


unsigned int M1EN;	// Enable
unsigned int M1NA;	// Direction
unsigned int M1NB;	// Direction
unsigned int M1PWM;	// PWM signal
unsigned int M1CS;	// Current sense

int main(int argc, char *argv[]){
	int i;
	
	printf("Testing the GPIO Pins\n");

	M1EN = gpio_no(0,30);	// P9-11
	M1NA = gpio_no(1,28);	// P9-12
	M1NB = gpio_no(0,31);	// P9-13
	M1CS = gpio_no(1,16);	// P9-15
	
	// echo n > export
        gpio_export(M1EN);
	gpio_export(M1NA);
	gpio_export(M1NB);
	gpio_export(M1CS);
	
	// Set Direction, echo in/out > direction
        gpio_set_dir(M1EN, OUTPUT_PIN);
	gpio_set_dir(M1NA, OUTPUT_PIN);
	gpio_set_dir(M1NB, OUTPUT_PIN);
	gpio_set_dir(M1CS, INPUT_PIN);
	
	// echo 1/0 > value
	gpio_set_value(M1EN, LOW);
	gpio_set_value(M1NA, LOW);
	gpio_set_value(M1NB, LOW);
	gpio_set_value(M1CS, LOW);
	
	
	
	// Flash the LED 5 times
	for(i=0; i<100; i++){
		printf("Setting the M1EN on\n");
                gpio_set_value(M1NA, HIGH);
		usleep(200000);         // on for 200ms
		printf("Setting the M1EN off\n");
                gpio_set_value(M1NA, LOW);
		usleep(200000);         // off for 200ms
	}

	/*

	unsigned int value = LOW;
	do {
		gpio_get_value(ButtonGPIO, &value); 
		printf(".");
		usleep(1000);      // sleep for one millisecond
	} while (value!=HIGH);
	printf("\nButton was just pressed!\n");
      */
      
	printf("Finished Testing the GPIO Pins\n");
	gpio_unexport(M1EN);
	gpio_unexport(M1NA);
	gpio_unexport(M1NB);
	gpio_unexport(M1CS);
	return 0;
}
