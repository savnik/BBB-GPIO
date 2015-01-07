CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o bbb-gpio  gpio.c pwm.c motor_test.c
stable:clean
	$(CC) $(CFLAGS) -o bbb-gpio gpio.c pwm.c motor_test.c
clean:
	rm -vfr *~ bbb-gpio
