#include <xc.h>
#define _XTAL_FREQ 6000000 //6mhz 
unsigned char pwm20_high,pwm20_low; 
unsigned char pwm60_high,pwm60_low;
unsigned char pwm90_high,pwm90_low;
void pwm_init(void);
void pwm_dutycycle_update(void);
void main(){
    pwm_init();
    while(1){
        pwm_dutycycle_update();
    }
}
void pwm_init(void){
    TRISC = 0XFB; //1111 1011 pin configuration RC2
    CCP1CON = 0x0C; //Configure CCP1 module for PWM mode
    PR2 = 0X2D;//period - 2khz frequency
    T2CON = 0X06;// for setting prescalar value(16)
    pwm20_high = 0x09; //configuring first 6 bits from MSB
    pwm20_low = 0x02;  // in CCP1CON (by taking first two LSB bits)
    pwm60_high = 0x1C;  //in CCPR1L
    pwm60_low = 0x01;   //in CCP1CON 
    pwm90_high = 0x2A; //in CCPR1L
    pwm90_low = 0x01; //in CCP1CON
}
//
void pwm_dutycycle_update(void){
    //set 20% duty cycle
    CCPR1L = pwm20_high; //20% High 8 bits
    CCP1CON = ((CCP1CON & 0xCF) | (pwm20_low << 4)); //20% low 2 bits
   __delay_ms(3000); //waiting for 3 seconds
   //set 60% duty cycle
   CCPR1L = pwm60_high; //60% High 8 bits
    CCP1CON = ((CCP1CON & 0xCF) | (pwm60_low << 4)); //60% low 2 bits
   __delay_ms(3000); //waiting for 3 seconds
   //set 90% duty cycle
   CCPR1L = pwm90_high; //90% High 8 bits
    CCP1CON = ((CCP1CON & 0xCF) | (pwm90_low << 4)); //90% low 2 bits
   __delay_ms(3000); //waiting for 3 seconds
}
