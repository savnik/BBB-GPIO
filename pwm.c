

#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

/****************************************************************
 * pwm_export
 ****************************************************************/
int pwm_export(unsigned int pwm)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
	if (fd < 0) {
		perror("pwm/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pwm);
	write(fd, buf, len);
	close(fd);

	return 0;
}

/****************************************************************
 * pwm_unexport
 ****************************************************************/
int pwm_unexport(unsigned int pwm)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
	if (fd < 0) {
		perror("pwm/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pwm);
	write(fd, buf, len);
	close(fd);
	return 0;
}

/****************************************************************
 * pwm_set_dir
 ****************************************************************/
int pwm_set_dir(unsigned int pwm, PIN_DIRECTION out_flag)
{
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR  "/pwm%d/direction", pwm);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("pwm/direction");
		return fd;
	}

	if (out_flag == OUTPUT_PIN)
		write(fd, "out", 4);
	else
		write(fd, "in", 3);

	close(fd);
	return 0;
}

/****************************************************************
 * pwm_set_value
 ****************************************************************/
int pwm_set_value(unsigned int pwm, PIN_VALUE value)
{
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/pwm%d/value", pwm);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("pwm/set-value");
		return fd;
	}

	if (value==LOW)
		write(fd, "0", 2);
	else
		write(fd, "1", 2);

	close(fd);
	return 0;
}

/****************************************************************
 * pwm_get_value
 ****************************************************************/
int pwm_get_value(unsigned int pwm, unsigned int *value)
{
	int fd;
	char buf[MAX_BUF];
	char ch;

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/pwm%d/value", pwm);

	fd = open(buf, O_RDONLY);
	if (fd < 0) {
		perror("pwm/get-value");
		return fd;
	}

	read(fd, &ch, 1);

	if (ch != '0') {
		*value = 1;
	} else {
		*value = 0;
	}

	close(fd);
	return 0;
}


/****************************************************************
 * pwm_set_edge
 ****************************************************************/

int pwm_set_edge(unsigned int pwm, char *edge)
{
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/pwm%d/edge", pwm);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("pwm/set-edge");
		return fd;
	}

	write(fd, edge, strlen(edge) + 1);
	close(fd);
	return 0;
}

/****************************************************************
 * pwm_fd_open
 ****************************************************************/

int pwm_fd_open(unsigned int pwm)
{
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/pwm%d/value", pwm);

	fd = open(buf, O_RDONLY | O_NONBLOCK );
	if (fd < 0) {
		perror("pwm/fd_open");
	}
	return fd;
}

/****************************************************************
 * pwm_fd_close
 ****************************************************************/

int pwm_fd_close(int fd)
{
	return close(fd);
}


/****************************************************************
 * Calculate GPIO NO
 * pwm[0]28
 * bank = 0, n = 28
 * return 28
 ****************************************************************/

int pwm_no(int bank, int n){
  return bank*32+n;  
}