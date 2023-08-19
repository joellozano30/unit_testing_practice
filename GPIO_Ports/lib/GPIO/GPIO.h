#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#define GPIO_OK 0

int GPIO_SetPinAsOutput(uint8_t Pin);
int GPIO_SetPinAsInput(uint8_t Pin);
int GPIO_SetPin(uint8_t Pin);
int GPIO_ClearPin(uint8_t Pin);


#endif //GPIO_H
