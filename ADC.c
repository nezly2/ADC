#include <stdio.h>
#include "gpio.h"
#include "adc.h"

int main(void){

		pinMode('B',18, OUTPUT);				//configurar rojo
		pinMode('B',19, OUTPUT);				//configurar verde
		pinMode('D',1, OUTPUT);					//configurar azul
		pinMode('C',2, INPUT);					//configurar boton
		digitalWrite('B',18,ON);				//apagar rojo
		digitalWrite('B',19,ON);				//apagar verde
		digitalWrite('D',1,ON);					//apagar azul

		codigo();
}

