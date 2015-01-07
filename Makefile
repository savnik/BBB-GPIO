CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o bbb-gpio main.c gpio.c pwm.c
stable:clean
	$(CC) $(CFLAGS) -o bbb-gpio main.c gpio.c pwm.c
clean:
	rm -vfr *~ bbb-gpio
