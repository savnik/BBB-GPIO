#ifndef PWM_H_
#define PWM_H_

 /****************************************************************
 * Constants
 ****************************************************************/

#define SYSFS_PWM_DIR "/sys/class/PWM"
#define POLL_TIMEOUT (3 * 1000) /* 3 seconds */
#define MAX_BUF 64

typedef enum{
	INPUT_PIN=0,
	OUTPUT_PIN=1
} PIN_DIRECTION;

typedef enum{
	LOW=0,
	HIGH=1
} PIN_VALUE;

/****************************************************************
 * pwm_export
 ****************************************************************/
int pwm_export(unsigned int pwm);
int pwm_unexport(unsigned int pwm);
int pwm_set_dir(unsigned int pwm, PIN_DIRECTION out_flag);
int pwm_set_value(unsigned int pwm, PIN_VALUE value);
int pwm_get_value(unsigned int pwm, unsigned int *value);
int pwm_set_edge(unsigned int pwm, char *edge);
int pwm_fd_open(unsigned int pwm);
int pwm_fd_close(int fd);
int pwm_no(int bank, int n);

#endif /* GPIO_H_ */