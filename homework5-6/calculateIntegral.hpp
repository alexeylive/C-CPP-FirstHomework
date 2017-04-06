//
// Created by alex on 06.04.17.
//

#ifndef HOMEWORK6_CALCULATEINTEGRAL_HPP
#define HOMEWORK6_CALCULATEINTEGRAL_HPP
#include "polynom.hpp"


class calculateIntegral {
protected:
	double a,b, segments;
public:
	calculateIntegral();
	void getBorders(double a, double b);
	virtual double  calculate(Polynom& func) = 0;
	virtual double  calculate(double (*func)(double x)) = 0;
	virtual ~calculateIntegral() = default;
};

class SimpsonMethod : public calculateIntegral {
public:
	SimpsonMethod();
	virtual double  calculate(double (*func)(double x));
	virtual double  calculate(Polynom& func);
	virtual  ~SimpsonMethod(){std::cout << "destr sim" << std::endl;};
};

class rectangleMethod : public calculateIntegral {
public:
	rectangleMethod();
	virtual double  calculate(Polynom& func) ;
	virtual double  calculate(double (*func)(double x));
	virtual  ~rectangleMethod(){std::cout << "destr rec" << std::endl;};
};


#endif //HOMEWORK6_CALCULATEINTEGRAL_HPP
