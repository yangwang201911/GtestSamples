#include "main.h"
#include "advanced_test.h"

TEST_P(CorrectConfigTestP, smoke_checkWithCorrectConfig) {
    ASSERT_NO_THROW(::setConfig(deviceName, flag));
}

TEST_P(InCorrectConfigTestP, smoke_checkWithInCorrectConfig) {
    ASSERT_THROW(::setConfig(deviceName, flag), std::runtime_error);
}