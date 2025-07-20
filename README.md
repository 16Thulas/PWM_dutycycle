# PWM_dutycycle
The project deals with the pwm(pulse width modulation) which efficiently deals with the pic16f877a by three different duty cycles 20 , 60, 90 with the low and high variations .
With setting of RC2 pin as low with the configuration of CCP1 module for PWM MODE with 2khz frequency and setting of prescalar vlaue (16)
By the configuration of 20 , 60 and 90 percent duty cycles , CCPR1L  registers are made to set with the delay provided for each high and low pulse
Considering this way Three levels of pulses are produced with mentioned period of time
