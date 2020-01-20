#include "Filekezeles.h"
#include <fstream>
#include <exception>
#include <iostream>

Filekezeles::Filekezeles() : fileStream("text.txt")
{
	try
	{
		if (!fileStream)
			throw;

		char buffer[255];

		while (fileStream >> buffer)
		{
			std::cout << buffer << std::endl;
		}
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
	}
}
Filekezeles::~Filekezeles()
{
	delete[] name;

	fileStream.close();
}
