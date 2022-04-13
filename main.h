#ifndef __MAIN_H__
#define __MAIN_H__

#include <gmock/gmock.h>
#include <iostream>
int myFunction(int x );

int setConfig(std::string deviceName, std::string flag);

class StuBase{
	public:
		StuBase(int age, std::string name){
			this->age = age;
			this->name = name;
		}
		void setName(std::string name)
		{
			this->name = name;
		}
		virtual bool lessonList(std::string& name, std::string &list) = 0;
		std::string getName(){
			return name;
		}
		~StuBase(){

		}
		bool displayLessonsList(StuBase *sPtr){
			std::cout << "Calling displayLessonsList...\n";
			std::string name, lessons;
			return sPtr->lessonList(lessons, name);
		}
	private:
		int age;
		std::string name;

};

class Primary: public StuBase{
	public:
		Primary(int age, std::string name, std::string lessons = ""): StuBase(age, name){
			this->lessons = lessons;
		}
		~Primary(){
		}
		void setLessons(std::string & lessons)
		{
			this->lessons = lessons;
		}
		bool lessonList(std::string & name, std::string& list){
			std::cout << "Lessons list from Primary Student: " << lessons << ".\n";
			if(lessons.empty())
				return false;
			list = lessons;
			name = this->getName();
			return true;
		}
	private:
		std::string lessons;
};

#endif
