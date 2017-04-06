//
// Created by alex on 06.04.17.
//

#include "calculateIntegral.hpp"
#include <iostream>
#include <cmath>


calculateIntegral::calculateIntegral() :
		a(0),
		b(0),
		segments(1)
{
}

void
calculateIntegral::getBorders(double a, double b)
{
	if (a>b) {
		this->a = b;
		this->b = a;
	} else {
		this->a = a;
		this->b = b;
	}
	this->segments = round((this->b - this->a) / 1e-3 + 1);
}


double
SimpsonMethod::calculate(Polynom& func)
{
	double h, s = 0, s1, s2;
	int i;

		h = (b - a) / segments;

		s1 = 0;
		for (i = 2; i < 2 * segments - 1; i += 2)
			s1 += func.valueOfPoint (a + h*i/2);

		s2 = 0;
		for (i = 1; i < 2 * segments; i += 2)
			s2 += func.valueOfPoint  (a + h*i/2);

		s = h / 6 * (func.valueOfPoint(a) + 2 * s1 + 4 * s2 + func.valueOfPoint(a + h*segments));


	std::cout << "Simpson's method: " << s << std::endl ;
	return s;
}



SimpsonMethod::SimpsonMethod() :
calculateIntegral()
{
}

double
SimpsonMethod::calculate(double (*func)(double))
{

	double h, s = 0, s1, s2;
	int i;

		h = (b - a) / segments;

		s1 = 0;
		for (i = 2; i < 2 * segments - 1; i += 2)
			s1 += func(a + h*i/2);

		s2 = 0;
		for (i = 1; i < 2 * segments; i += 2)
			s2 += func(a + h*i/2);

		s = h / 6 * (func(a) + 2 * s1 + 4 * s2 + func(a + h*segments));


	std::cout << "Simpson's method: " << s << std::endl ;
	return s;
}


double
rectangleMethod::calculate(Polynom& func)
{
	double h, S, x;
	h = (b - a) / segments;
	S=0;
	for(int i = 0; i < segments - 1; i++)
	{
		x = a + i*h;
		S += func.valueOfPoint(x);
	}
	S=h*S;
	std::cout << "Rectangle method: " << S << std::endl ;
	return S;
}

rectangleMethod::rectangleMethod() :
calculateIntegral()
{
}

double
rectangleMethod::calculate(double (* func)(double))
{
	double h, S, x;
	h = (b - a) / segments;
	S=0;
	for(int i = 0; i < segments - 1; i++)
	{
		x = a + i*h;
		S += func(x);
	}
	S=h*S;
	std::cout << "Rectangle method: " << S << std::endl ;
	return S;
}

