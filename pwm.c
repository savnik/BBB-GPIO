

#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

/****************************************************************
 * pwm_set_duty
 * \input duty period in ns
 ****************************************************************/
int pwm_set_duty(unsigned int duty)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_PWM_DIR "/duty", O_WRONLY);
	if (fd < 0) {
		perror("/duty");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", duty);
	write(fd, buf, len);
	close(fd);

	return 0;
}

/****************************************************************
 * pwm_set_period
 * \input period in ns
 ****************************************************************/
int pwm_set_period(unsigned int period)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_PWM_DIR "/period", O_WRONLY);
	if (fd < 0) {
		perror("/period");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", period);
	write(fd, buf, len);
	close(fd);

	return 0;
}

/****************************************************************
 * pwm_set_polarity
 * \input 1/0
 ****************************************************************/
int pwm_set_polarity(unsigned int polarity)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_PWM_DIR "/duty", O_WRONLY);
	if (fd < 0) {
		perror("/duty");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", polarity);
	write(fd, buf, len);
	close(fd);

	return 0;
}


/****************************************************************
 * pwm_set_enable
 * \input 1/0
 ****************************************************************/
int pwm_set_enable(unsigned int enable)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_PWM_DIR "/run", O_WRONLY);
	if (fd < 0) {
		perror("/run");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", enable);
	write(fd, buf, len);
	close(fd);

	return 0;
}



