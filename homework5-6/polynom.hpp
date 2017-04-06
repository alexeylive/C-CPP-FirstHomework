#ifndef _POLYNOM_HPP_
#define _POLYNOM_HPP_
#include "iostream"

class Polynom{
public:
    Polynom();
    Polynom(const Polynom& rhs);
	Polynom(const unsigned int deg);
	Polynom(const unsigned int deg, const int* coef);
    ~Polynom();
    Polynom operator + (const Polynom& B) const;
	Polynom operator - (const Polynom& B) const;
	Polynom operator * (const Polynom& B);
	Polynom operator = (const Polynom& B); // возвращать *this
	unsigned int getDeg() const;
	int getCoef (const int i) const;
	void setDeg (const unsigned int deg);
	void setCoef (const int i, const int value);
	void setMemory (unsigned int deg);
	double valueOfPoint(double x);
private:
  unsigned int deg;
  int* coef;
  void correctDeg();
};

Polynom sumOfPolynomials (const Polynom* array, const int N);
std::ostream& operator << (std::ostream& os, const Polynom& B);

#endif
