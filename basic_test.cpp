#include <gtest/gtest.h>
#include "main.h"
#include "advanced_test.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicUsage) {
  	// Expect two strings not to be equal.
  	EXPECT_STRNE("hello", "world");
  	// Expect equality.
  	EXPECT_EQ(7 * 6, 42);
}

// Demonstrate expection for the function call.
TEST(HelloTest, smoke_callMyFunctionNoThrowTest) {
	ASSERT_THROW(myFunction(-1), std::runtime_error);
	//ASSERT_NO_THROW(myFunction(-1));
	int val = 0;
	ASSERT_NO_THROW(val = myFunction(11));
  	EXPECT_EQ(12, val);
}



INSTANTIATE_TEST_SUITE_P(
        smoke_CPU_TestSuit, CorrectConfigTestP,
        ::testing::Values(
			std::make_pair("CPU", "YES"),
			std::make_pair("CPU", "NO")
		));

INSTANTIATE_TEST_SUITE_P(
        smoke_CPU_TestSuit, InCorrectConfigTestP,
        ::testing::Values(
			std::make_pair("CPU", "NON"),
			std::make_pair("CPU", "ENABLE"),
			std::make_pair("CPU", "DISABLE")
		));
