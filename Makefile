CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o bbb-gpio main.c
stable:clean
	$(CC) $(CFLAGS) -o bbb-gpio main.c
clean:
	rm -vfr *~ bbb-gpio
