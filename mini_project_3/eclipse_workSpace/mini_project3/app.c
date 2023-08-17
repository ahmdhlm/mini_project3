#include "app.h"



int main (void){
	uint8 temp;
	ADC_ConfigType ADC_config={INTERNAL_VOLT,F_CPU_8};


	/*************TURN OFF THE FAN AT THE BEGINING********/
	FAN_STATUES state=FAN_OFF;
	/*******Enable I bit **********/
	SREG |=(1<<7);

	/**********init functions************/
	LCD_init();
	DcMotor_Init();
	ADC_init(&ADC_config);




	while (1){

		temp=LM35_getTemperature();


		if (temp<30){
			state=FAN_OFF;
			DcMotor_Rotate(stop, LOGIC_LOW);

		}

		else if ( (temp>=30) && (temp<60))
		{
			state=FAN_ON;
			DcMotor_Rotate(CW,25);
		}

		else if ( (temp>=60) && (temp<90))
		{
			state=FAN_ON;
			DcMotor_Rotate(CW,50);
		}

		else if ( (temp>=90) && (temp<120))
		{
			state=FAN_ON;
			DcMotor_Rotate(CW,75);
		}


		else if ( (temp>=120) )
		{

			state=FAN_ON;

			DcMotor_Rotate(CW,100);
		}
		/*********** display state & temp ******************/
		LCD_moveCursor(1, 3);
		LCD_displayString("Temp = ");
		LCD_moveCursor(1, 10);

        if (temp>=100)
        {
        	LCD_intgerToString(temp);
        }
        else
        {
        	LCD_intgerToString(temp);
        	LCD_displayCharacter(' ');
        }
		LCD_moveCursor(0, 3);

		if (state ==FAN_ON){
			LCD_displayString("FAN IS ON");
			LCD_displayCharacter(' ');

		}
		else if (state ==FAN_OFF)
		{
			LCD_displayString("FAN IS OFF");
		}





	}
}
