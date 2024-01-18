#include <iostream>
#include <tuple>

#include "SSubject.h"

void exampleFunction(int a, double b)
{
	std::cout << "Example Function: " << a << ", " << b << std::endl;
}

void exampleFunction2(double a)
{
	std::cout << "Example Function: " << a << std::endl;
}

int main()
{
	SSubject subject;
	SObserver<int, double> observer(&exampleFunction, 42, 3.14);
	SObserver<double> observer2(&exampleFunction2, 3.14);

	subject.addObserver(&observer);
	subject.addObserver(&observer2);
	subject.notifyUpdate();

	return 0;
}