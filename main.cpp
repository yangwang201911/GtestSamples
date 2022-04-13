#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include "main.h"

int myFunction(int x)
{
	if(x <= 0)
		throw std::runtime_error("error");
	return x+1;
}

int setConfig(std::string deviceName, std::string flag)
{
	std::cout << "Parameters: " << deviceName << " - " << flag << std::endl;
	if(deviceName != "CPU" && deviceName != "GPU" && deviceName != "AUTO")
		throw std::runtime_error("Invalid Device");
	if(flag != "YES" && flag != "NO")
		throw std::runtime_error("Invalid flag");
	std::cout << "Set device-flag "  << "[" << deviceName << "-" << flag << "]\n";
	return 0;
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();   
}
