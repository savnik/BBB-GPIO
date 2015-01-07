CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o bbb-gpio main.c gpio.c pwm.h
stable:clean
	$(CC) $(CFLAGS) -o bbb-gpio main.c gpio.c pwm.h
clean:
	rm -vfr *~ bbb-gpio
