#include <stdio.h>
#include <stdlib.h>

//#include <iostream.h>
#include <string.h>
#include <unistd.h>
#include "gpio.h"
#include "pwm.h"


unsigned int M1EN;	// Enable
unsigned int M1NA;	// Direction
unsigned int M1NB;	// Direction
unsigned int M1CS;	// Current sense

int main(int argc, char *argv[]){
	int i = 0; 
	int t = 0;
	
	printf("Testing the Motor\n");

	M1EN = gpio_no(0,30);	// P9-11
	M1NA = gpio_no(1,28);	// P9-12
	M1NB = gpio_no(0,31);	// P9-13
	M1CS = gpio_no(1,19);	// P9-15
	
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
	gpio_set_value(M1NA, HIGH);
	gpio_set_value(M1NB, LOW);
	gpio_set_value(M1CS, LOW);
	
	// Setup PWM 
	pwm_set_enable(0);
	pwm_set_period(5000000);
	pwm_set_duty(0);
	pwm_set_polarity(1);
	
	// Setup motor
	printf("Setting up motor\n");
	gpio_set_value(M1EN, HIGH);
	printf("Motor Enable\n");
	pwm_set_duty(0);
	printf("Duty: 0\n");
	pwm_set_enable(1);
	printf("PWM enable\n");
	
	printf("Main loop started");
	while(1){
	    pwm_set_duty(i);
	    if(i >= 5000000){ 
	      t = 1;
	      printf("Toogle! 1\n");
	    }
	    if(i <= 0){ 
	      t = 0;
	      printf("Toogle! 0\n");
	    }
	    
	    if (t == 1){ 
	      i -= 10;
	    }
	    if (t == 0){ 
	      i += 10;
	    }
	      
	}
      
	printf("Finished Motor\n");
	gpio_unexport(M1EN);
	gpio_unexport(M1NA);
	gpio_unexport(M1NB);
	gpio_unexport(M1CS);
	pwm_set_enable(0);
	return 0;
}
