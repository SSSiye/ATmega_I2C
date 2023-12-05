//스마트모빌리티 2101069 이시예

#include "main.h"
#include "led_sw.h"
#include "fnd.h"
#include "i2c_temp.h"

//실습과제1
/*void main(void)
{
	byte bConfig;
	float fTempVal;
	
	led_init();
	fnd_init();
	i2c_init();
	
	// Temperature 레지스터 선택
	if(!i2c_aTS75_sel_reg(I2C_aTS75_REG_TEMP)) { led_on(LED_ALL); return; }
	_delay_ms(1);  //aTS75 동작 특성과 컴파일러 성능 때문에 필요한 경우가 있음.
	
	led_off(LED_ALL);
	int iPos = 0;
	int iLedOnOff = TRUE;
	while(TRUE) {
		// Temperature 레지스터 값 읽어서 실수로 변환
		fTempVal = i2c_aTS75_get_temp();
		fnd_set(fTempVal);
		
		if(fTempVal > 27) iPos++;
		
		else { iPos=0; led_off(LED_ALL); }
		
		for(int i=0; i<100; i++) {
			fnd_show();	// fnd_show() 100회 호출 --> 약 500[msec]
			if(iPos>0){
				if(iLedOnOff) led_on(LED_ALL);
				else led_off(LED_ALL);
			}
			if(i%20 == 0) iLedOnOff = !iLedOnOff;  //fnd_show()가 5[msec]를 소모하기때문에 20*5[msec] = 100[msec] 이다.
		}
	}
}*/


//실습과제2
/*void main(void)
{
	byte bConfig;
	float fTempVal;
	
	led_init();
	fnd_init();
	i2c_init();
	
	// Temperature 레지스터 선택
	if(!i2c_aTS75_sel_reg(I2C_aTS75_REG_TEMP)) { led_on(LED_ALL); return; }
	_delay_ms(1);  //aTS75 동작 특성과 컴파일러 성능 때문에 필요한 경우가 있음.
	
	
	led_off(LED_ALL);
	int cnt =0;
	int first_Temp;
	int iPos = 0;
	int iLedOnOff = TRUE;
	while(TRUE) {
		// Temperature 레지스터 값 읽어서 실수로 변환
		fTempVal = i2c_aTS75_get_temp();
		fnd_set(fTempVal);
		
		if(cnt==0){first_Temp = fTempVal; cnt++;}   //첫 온도 저장
			
		else {
			if(fTempVal-first_Temp >= 2) iPos=1;   //첫 온도 기준으로 2도 이상 증가하면 (온도증가량 >= 2도)
			else { iPos=0; led_off(LED_ALL); }     //온도 증가량이 2도 미만이면   (온도증가량 <2도)
		}
		for(int i=0; i<100; i++) {
			fnd_show();	// fnd_show() 100회 호출 --> 약 500[msec]
			
			if(iPos>0){
				if(iLedOnOff) led_on(LED_ALL);
				else led_off(LED_ALL);
			}
			if(i%20 == 0) iLedOnOff = !iLedOnOff;  //fnd_show()가 5[msec]를 소모하기때문에 20*5[msec] = 100[msec] 이다.
		}
	}
}*/


//실습과제3
void main(void)
{
	byte bConfig;
	float fTempVal;
	
	led_init();
	fnd_init();
	i2c_init();
	
	// Temperature 레지스터 선택
	if(!i2c_aTS75_sel_reg(I2C_aTS75_REG_TEMP)) { led_on(LED_ALL); return; }
	_delay_ms(1);  //aTS75 동작 특성과 컴파일러 성능 때문에 필요한 경우가 있음.
	
	
	led_off(LED_ALL);
	int cnt =0;
	int first_Temp;
	int iPos = 0;
	int iTime = 0;
	int iLedOnOff = TRUE;
	while(TRUE) {
		// Temperature 레지스터 값 읽어서 실수로 변환
		fTempVal = i2c_aTS75_get_temp();
		fnd_set(fTempVal);
		
		if(cnt==0){first_Temp = fTempVal; cnt++;}   //첫 온도 저장
		
		else {
			if(2 > fTempVal-first_Temp && fTempVal-first_Temp >= 1) { iPos =1; iTime = 40; }  //2도 > 온도증가량 >= 1도
			else if (fTempVal-first_Temp >= 2)  { iPos =1; iTime = 20; }  //      온도증가량 >= 2도
			else { iPos = 0; led_off(LED_ALL); }          // 1도 >온도증가량
		}
		for(int i=0; i<100; i++) {
			fnd_show();	// fnd_show() 100회 호출 --> 약 500[msec]
			
			if(iPos>0){
				if(iLedOnOff) led_on(LED_ALL);
				else led_off(LED_ALL);
			}
			if(i % iTime == 0) iLedOnOff = !iLedOnOff;
		}
	}
}