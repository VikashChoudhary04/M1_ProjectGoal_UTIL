#include"Banking_System.h"
#include"unity.h"
void test_accountCreated(void);

void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_accountCreated);


  /* Close the Unity Test Framework */
  return UNITY_END();
}

void test_accountCreated(void);
{
    char name[20]="Vikash";
    int i=100;
    TEST_ASSERT_EQUAL("Vikash", name);
    TEST_ASSERT_EQUAL(100, i);
   
}

