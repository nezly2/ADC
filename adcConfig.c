//adcConfig.c
//  Created on: Mar 23, 2021
//     Author: Nezly Yanez & Flavio Jimenez

void adcMode(){

	//clock
	int *p2SCGC5; 						//apuntador a clock
	p2SCGC5 = (int *) 0x40048038;
	*p2SCGC5 |= 0x400;					//prende el clock del Puerto B
	int *p2SCGC6; 						//apuntador a clock
	p2SCGC6 = (int *) 0x4004803C;
	*p2SCGC6 |= 0x8000000;				//prende el clock del ADC

	//PCR B2
	int *p2Pcrb2;						//apuntador a PCR
	p2Pcrb2 =  (int *) 0x4004A008;		//direccion de pin b2
	*p2Pcrb2 = 0x0;						//b2 esta configurado como analogo (potenciometro/termistor)

	//PTB2 = ADC0_SE12
	int *p2confReg1;					//apuntador a ADC Configuration Register 1 (ADCx_CFG1)
	p2confReg1 = (int *) 0x4003B008;	//direccion de ADC Configuration Register 1 (ADCx_CFG1)
	*p2confReg1 = 0x0;					//seleccionamos single-ended 8-bit conversion;

	int *p2confReg2;					//apuntador a ADC Configuration Register 2 (ADCx_CFG2)
	p2confReg2 = (int *) 0x4003B00C;	//direccion de ADC Configuration Register 2 (ADCx_CFG2)
	*p2confReg2 = 0x0;					//seleccionamos el canal A (ADC0_SC1A)

	int *p2SCR1;						//apuntador a ADC Status and Control Registers 1 (ADC0_SC1A)
	p2SCR1 = (int *) 0x4003B000;		//direccion de ADC Status and Control Registers 1 (ADC0_SC1A)
	*p2SCR1 = 0xC;						//01100 con diff 0

	return;
}

