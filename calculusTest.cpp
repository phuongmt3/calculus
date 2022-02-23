#include <iostream>
#include <cmath>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>


#include "calculus.h"

const double EPSILON = 0.0001;
const double PI = 3.14159265359;

struct TestStruct
{
    std::string testName;
    bool result;
    bool expected;
    std::string errorMsg;
};

bool isClose(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

void runTestLoop(TestStruct testCases[], int testSize){
    int i;
    for (i = 0; i< testSize; i++){
        if (testCases[i].result == testCases[i].expected)
        {
            std::cout << testCases[i].testName + "- PASSED";
        }
        else
        {
            std::cout << testCases[i].errorMsg;
            exit(1);
        }
    }
}

class Test
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testMyCos);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  void testMyCos(void){
      int testSize = 3;
      TestStruct testCases[testSize]  = 
      {
          {
              "test normal", isClose(myCos(0), cos(0)), true, "Cos(0) should close to myCode(0)"
          },
          {
              "test normal", isClose(myCos(-1 * PI/3), cos(PI/3)), true, "Cos(-1 * PI/3) should close to " + std::to_string(cos(PI/3))
          },
          {
              "test normal", isClose(myCos(PI/3), cos(PI/6)), false, "Cos(PI/3) should not close to " + std::to_string(cos(PI/6))
          },
      };
      runTestLoop(testCases, testSize);
      exit(0);
  }
};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()
{
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}