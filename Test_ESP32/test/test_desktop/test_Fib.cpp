
#include <unity.h>
#include "Fib.h"
#include "limits.h"

#define DIMENSION_OF(a) (sizeof(a)/sizeof(a[0]))

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


void test_TheFirst(void)
{
    TEST_IGNORE_MESSAGE("Implement Me");
}

void test_number_is_in_fib_sequence (void){
    //int i=0;
    const int first_bad_element = 47;
    const int last_good_element = first_bad_element - 1;
    int last_good_value = Fibonacci_GetElement(last_good_element);

    TEST_ASSERT_MESSAGE(last_good_value > 1,"This value should not have been a rollover");

    TEST_ASSERT_EQUAL_INT_MESSAGE(4, sizeof(int), "Constant first_bad_element must be changed");
    //Generacion de los Fibonacci

    /*int expected[47]={};

    for(i=0;i<47;i++){
        expected[i] = Fibonacci_GetElement(i);
    }
    //TEST_ASSERT_EQUAL(18363111903,expected[46]);
    */

    
    TEST_ASSERT_EQUAL(1,Fibonacci_IsInSequence(last_good_value));
    

    //TEST_ASSERT_EQUAL(1,Fibonacci_IsInSequence(expected[3]));
    //TEST_ASSERT_EQUAL(1,Fibonacci_IsInSequence(3));
}

int main(void) {
    //delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_TheFirst);
    RUN_TEST(test_number_is_in_fib_sequence);
    return UNITY_END();
}
