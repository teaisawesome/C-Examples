#pragma once
#include <fstream>

class Filekezeles
{
	char* name;
	unsigned int age;
	std::ifstream fileStream;

public:

	Filekezeles();
	~Filekezeles();

	inline char* getName()  { return name; }
	inline unsigned int getAge() { return age; }

};
