CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o bbb-gpio main.c gpio.c
stable:clean
	$(CC) $(CFLAGS) -o bbb-gpio main.c gpio.c
clean:
	rm -vfr *~ bbb-gpio
