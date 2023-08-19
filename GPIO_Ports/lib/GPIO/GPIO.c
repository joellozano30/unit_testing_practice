#include "GPIO.h"
#include <MK20DX256.h>

int GPIO_SetPinAsOutput(uint8_t Pin){
    if(Pin >= 32)
        return 1;
    PORTC.PDDR|=BIT_TO_MASK(Pin);
    return 0;
}
int GPIO_SetPinAsInput(uint8_t Pin){
    if(Pin >= 32)
        return 1;
    PORTC.PDDR &= ~(BIT_TO_MASK(Pin));
    return 0;
}
int GPIO_SetPin(uint8_t Pin){
    uint32_t Mask = BIT_TO_MASK(Pin);
    if(Mask == 0)
        return 1;
    PORTC.PSOR = Mask;
    if(!(PORTC.PDDR & Mask))
        PORTC.PDDR|=Mask;    
    return 0;
}
int GPIO_ClearPin(uint8_t Pin){
    return 1;
}