#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock_test.h"

using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;
using ::testing::StrEq;

class MockPrimaryTest: public ::testing::Test {
    public:
        StuBase *sPtr;
        MockPrimary * mpPtr;

    public:
        void SetUp() override {
            mpPtr = new MockPrimary(10, "Yang", "Math, Music");
            sPtr = mpPtr;
        }
        void TearDown() override {
            delete mpPtr;
            sPtr = NULL;
            mpPtr = NULL;
        }
};

TEST_F(MockPrimaryTest, baseTestwithoutThrow) {
    ON_CALL(*mpPtr, lessonList(StrEq("Wang"),_))
            .WillByDefault(Return(false));
    EXPECT_CALL(*mpPtr, lessonList(_, _)).Times(2);

    ASSERT_NO_THROW(sPtr->displayLessonsList(sPtr));

    bool value = true;
    std::string name = "Wang";
    std::string ret;
    ASSERT_NO_THROW(value = mpPtr->lessonList(name, ret));

    EXPECT_FALSE(value);
}

TEST_F(MockPrimaryTest, withoutThrow) {
    ON_CALL(*mpPtr, lessonList(StrEq("Yang"),_))
            .WillByDefault(
                [&](std::string& name, std::string& lessons){
                    std::cout << "== Return Yang's lessons ==\n";
                    return true;
                }
            );
    EXPECT_CALL(*mpPtr, lessonList(_, _)).Times(1);
    bool value = false;
    std::string name = "Yang";
    std::string ret;
    ASSERT_NO_THROW(value = mpPtr->lessonList(name, ret));
    EXPECT_TRUE(value);
}
