#include <iostream>
#include "calculateIntegral.hpp"
#include <cmath>

double
func1(double x)
{
	return sin(x);
}



int
main()
{
	Polynom func (2);
	func.setCoef(2,1);

	double (*x)(double) = func1;

	std::cout << func << std::endl;

	calculateIntegral* calc[2];

	calc[0] = new rectangleMethod;
	calc[1] = new SimpsonMethod;

	calc[0]->getBorders(1,0);
	calc[1]->getBorders(0,1);


	calc[0]->calculate(func);
	calc[1]->calculate(func);

	calc[0]->calculate(x);
	calc[1]->calculate(x);

	delete calc[0];
	delete calc[1];
	return 0;
}