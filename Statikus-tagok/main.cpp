#include "StaticA.h"
#include <iostream>

int StaticA::count = 0;

int main()
{
	StaticA a;
	StaticA* pa = new StaticA;
	
	std::cout << "Object count: " << StaticA::GetCount() << std::endl; //2

	delete pa;

	return 0;
}
