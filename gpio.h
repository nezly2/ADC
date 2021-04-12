//library.h
//  Created on: Mar 23, 2021
//     Author: Nezly Yanez & Flavio Jimenez

#ifndef GPIO_H_
#define GPIO_H_

#define OUTPUT 1
#define INPUT 0
#define ON 1
#define OFF 0

	void pinMode(unsigned char puerto, int bit, unsigned char mode);
	void digitalWrite(unsigned char puerto, int bit, unsigned char data);

#endif /* GPIO_H_ */
