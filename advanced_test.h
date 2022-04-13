#ifndef __ADVANCED_TEST_H__
#define __ADVANCED_TEST_H__

#include <gtest/gtest.h>

class AdvancedTestP : public ::testing::Test,
                          public ::testing::WithParamInterface<std::pair<std::string, std::string>> {
    public:
        std::string deviceName;
        std::string flag;
    public:
        void SetUp() override {
            std::tie(deviceName, flag) = GetParam();
        }

};

using CorrectConfigTestP = AdvancedTestP;
using InCorrectConfigTestP = AdvancedTestP;

#endif
