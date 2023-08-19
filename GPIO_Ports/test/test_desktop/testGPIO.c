#include <GPIO.h>
#include <MK20DX256.h>
#include <unity.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_SetPinAsOutput_should_ConfigurePinDirection(void)
{
    PORTC.PDDR = 0;
    
    TEST_ASSERT_EQUAL(GPIO_OK,GPIO_SetPinAsOutput(0));
    TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0),PORTC.PDDR);

    TEST_ASSERT_EQUAL(GPIO_OK,GPIO_SetPinAsOutput(22));
    TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0)|BIT_TO_MASK(22),PORTC.PDDR);

    TEST_ASSERT_EQUAL(GPIO_OK,GPIO_SetPinAsOutput(31));
    TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0)|BIT_TO_MASK(22)|BIT_TO_MASK(31),PORTC.PDDR);
    //TEST_IGNORE_MESSAGE("Implement Me");
}

void test_SetPinAsInput_should_ConfigurePinDirection(void)
{
    PORTC.PDDR = 0xFFFFFFFF;
    
    TEST_ASSERT_EQUAL(GPIO_OK,GPIO_SetPinAsInput(0));
    TEST_ASSERT_EQUAL_HEX32(~(BIT_TO_MASK(0)),PORTC.PDDR);

    TEST_ASSERT_EQUAL(GPIO_OK,GPIO_SetPinAsInput(16));
    TEST_ASSERT_EQUAL_HEX32(~(BIT_TO_MASK(0)|BIT_TO_MASK(16)),PORTC.PDDR);

    TEST_ASSERT_EQUAL(GPIO_OK,GPIO_SetPinAsInput(31));
    TEST_ASSERT_EQUAL_HEX32(~(BIT_TO_MASK(0)|BIT_TO_MASK(16)|BIT_TO_MASK(31)),PORTC.PDDR);
    //TEST_IGNORE_MESSAGE("Implement Me");
}

void test_SetPinAsOutput_should_NotUpdatePinDirection_when_PinIsNotValid(void){

    PORTC.PDDR = 0;

    TEST_ASSERT_NOT_EQUAL(0,GPIO_SetPinAsOutput(32));
    TEST_ASSERT_EQUAL_HEX32(0,PORTC.PDDR);

}

void test_SetPinAsInput_should_NotUpdatePinDirection_when_PinIsNotValid(void){

    PORTC.PDDR = 0xFFFFFFFF;

    TEST_ASSERT_NOT_EQUAL(0,GPIO_SetPinAsInput(32));
    TEST_ASSERT_EQUAL_HEX32(0xFFFFFFFF,PORTC.PDDR);

}

void test_setPin_should_SetOutputHigh(void){
    PORTC.PSOR = 0;
    PORTC.PCOR = 0;

    TEST_ASSERT_EQUAL(0,GPIO_SetPin(0));
    TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0),PORTC.PSOR); //Registers are as expected
    TEST_ASSERT_EQUAL_HEX32(0,PORTC.PCOR);
}

void test_SetPin_should_ForceToOutput_when_ConfiguredAsInput(void){
    PORTC.PSOR = 0;
    PORTC.PCOR = 0;
    PORTC.PDDR = 0x50000000;

    TEST_ASSERT_EQUAL(0, GPIO_SetPin(0));
    TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0), PORTC.PSOR);
    TEST_ASSERT_EQUAL_HEX32(0, PORTC.PCOR);
    TEST_ASSERT_EQUAL_HEX32(0X50000001, PORTC.PDDR);
}

void test_SetPin_should_NotSetOutputs_when_PinIsNotValid(void){
    PORTC.PSOR = 0;
    PORTC.PCOR = 0;
    PORTC.PDDR = 0;

    TEST_ASSERT_NOT_EQUAL(0, GPIO_SetPinAsOutput(32));
    TEST_ASSERT_EQUAL_HEX32(0, PORTC.PSOR);
    TEST_ASSERT_EQUAL_HEX32(0, PORTC.PCOR);
    TEST_ASSERT_EQUAL_HEX32(0, PORTC.PDDR);
    
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_SetPinAsOutput_should_ConfigurePinDirection);
    RUN_TEST(test_SetPinAsOutput_should_NotUpdatePinDirection_when_PinIsNotValid);
    RUN_TEST(test_SetPinAsInput_should_ConfigurePinDirection);
    RUN_TEST(test_SetPinAsInput_should_NotUpdatePinDirection_when_PinIsNotValid);
    RUN_TEST(test_setPin_should_SetOutputHigh);
    RUN_TEST(test_SetPin_should_ForceToOutput_when_ConfiguredAsInput);
    RUN_TEST(test_SetPin_should_NotSetOutputs_when_PinIsNotValid);
    return UNITY_END();
}
