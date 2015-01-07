#ifndef PWM_H_
#define PWM_H_

 /****************************************************************
 * Constants
 ****************************************************************/

#define SYSFS_PWM_DIR "/sys/devices/ocp.3/pwm_test_P9_14.17"
#define POLL_TIMEOUT (3 * 1000) /* 3 seconds */
#define MAX_BUF 64


/****************************************************************
 * pwm_export
 ****************************************************************/

int pwm_set_duty(unsigned int duty);
int pwm_set_period(unsigned int period);
int pwm_set_polarity(unsigned int polarity);
int pwm_set_enable(unsigned int enable);



#endif /* PWM_H_ */