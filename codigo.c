#include "gpio.h"
#include "adc.h"

void bounce();

void codigo(){
	int *p2ADCresult = (int *) 0x4003B010;	//apuntador para ADC Data Result Register (ADCx_Rn)
	int *p2boton = (int *) 0x400FF090;		//apuntador para boton

	adcMode();

	while(1)
	{
		if(*p2ADCresult > 100)
		{
			for(int i=0; i<1000000; ++i)			//1700000 aprox 10 segundos
			{
				adcMode();
				if(*p2ADCresult < 100)
					i=0;
			}
			while((*p2boton & 0x4) != 0x4)
			{
					bounce();
			}
		}
	}
}

void bounce(){
	int i;

	digitalWrite('B',18,OFF);		//estado 0: rojo
	for(i=0; i<1000000; ++i);
	digitalWrite('B',18,ON);

	digitalWrite('B',19,OFF);		//estado 1: verde
	for(i=0; i<1000000; ++i);
	digitalWrite('B',19,ON);

	digitalWrite('D',1,OFF);		//estado 2: azul
	for(i=0; i<1000000; ++i);
	digitalWrite('D',1,ON);

	digitalWrite('D',1,OFF);		//estado 3: magenta
	digitalWrite('B',18,OFF);
	for(i=0; i<1000000; ++i);
	digitalWrite('D',1,ON);
	digitalWrite('B',18,ON);

	digitalWrite('D',1,OFF);		//estado 4: azul
	for(i=0; i<1000000; ++i);
	digitalWrite('D',1,ON);

	digitalWrite('B',19,OFF);		//estado 5: verde
	for(i=0; i<1000000; ++i);
	digitalWrite('B',19,ON);

	digitalWrite('B',18,OFF);		//estado 6: rojo
	for(i=0; i<1000000; ++i);
	digitalWrite('B',18,ON);
}
