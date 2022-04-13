#ifndef __MOCK_TEST_H__
#define __MOCK_TEST_H__

#include <gmock/gmock.h>
#include "main.h"

class MockPrimary : public Primary{
	public:
		MockPrimary(int age, std::string name, std::string lessons) : Primary(age,name, lessons){
		}
		MOCK_METHOD(bool, lessonList, (std::string&, std::string &), (override));
};

#endif
