#include "advanced_test.h"

INSTANTIATE_TEST_SUITE_P(
        smoke_GPU_TestSuit, CorrectConfigTestP,
        ::testing::Values(
			std::make_pair("GPU", "YES"),
			std::make_pair("GPU", "NO")
		));

INSTANTIATE_TEST_SUITE_P(
        smoke_GPU_TestSuit, InCorrectConfigTestP,
        ::testing::Values(
			std::make_pair("GPU", "NON"),
			std::make_pair("GPU", "ENABLE"),
			std::make_pair("GPU", "DISABLE")
		));

