#include <iostream>
using namespace std;
#include "polynom.hpp"
#include <cmath>

Polynom::Polynom():
deg(0)
{
  this->coef = new int[1];
  this->coef[0] = 0;
}

double Polynom::valueOfPoint(double x) {
double sum = 0;

for(int i = 0; i <= this->deg; i++)
sum = sum + this->coef[i] * pow(x,i); // для pow либо double либо float

return sum;
}

Polynom::Polynom(const Polynom& rhs):
deg(rhs.deg)
{
  this->coef = new int[deg + 1];

  for (int i = 0; i <= deg; i++)
    this->coef[i] = rhs.coef[i];  //memcpy
}

Polynom::Polynom(const unsigned int deg) :
deg(deg)
{
	this->coef = new int[this->deg + 1]; // конструктор делигирования

	for (int i = 0; i <= this->deg; i++)
		this->coef[i] = 0;
}

Polynom::Polynom(const unsigned int deg, const int* coef) :
deg(deg)
{
  this->coef = new int[this->deg + 1];

  for (int i = 0; i <= this->deg; i++) {
	this->coef[i] = coef[i];
  }
}

Polynom::~Polynom() {
  delete[] coef;
}

Polynom Polynom::operator + (const Polynom& B) const {
   if (this->deg == B.deg) {
 	  Polynom A(*this);

 	  for (int i = 0; i <= A.deg; i++)
 		  A.coef[i] = A.coef[i] + B.coef[i];

	   A.correctDeg();
	   return A;
   }

   if (this->deg > B.deg) {
	  Polynom A(*this);

	  for (int i = 0; i <= B.deg; i++)
		  A.coef[i] = A.coef[i] + B.coef[i];

	   A.correctDeg();
	   return A;
   }

	Polynom A(B);

	for (int i = 0; i <= this->deg; i++)
		A.coef[i] = this->coef[i] + A.coef[i];

	A.correctDeg();
	return A;
}

Polynom Polynom::operator-(const Polynom& B) const {
	if (this->deg == B.deg) {
		Polynom A(this->deg);

		for (int i = 0; i <= A.deg; i++)
			A.coef[i] = this->coef[i] - B.coef[i];

		A.correctDeg();
		return A;
	}

	if (this->deg > B.deg) {
		Polynom A(*this);

		for (int i = 0; i <= B.deg; i++)
			A.coef[i] = this->coef[i] - B.coef[i];

		A.correctDeg();
		return A;
	}

	Polynom A(B.deg);

	for (int i = 0; i <= this->deg; i++)
		A.coef[i] =this->coef[i] - B.coef[i];

	for (int i = this->deg + 1; i <= B.deg; i++)
		A.coef[i] = - B.coef[i];

	A.correctDeg();
	return A;
}


int Polynom::getCoef(const int i) const {
	return this->coef[i];
}


unsigned int Polynom::getDeg() const {
	return this->deg;
}

void Polynom::setCoef(const int i, const int value) { // Проверка для ввода данных клиентом
	if (this->deg >= i)
	this->coef[i] = value;
}

void Polynom::setDeg(const unsigned int deg) {
	this->deg = deg;
}

Polynom Polynom::operator=(const Polynom& B) {
	this->deg = B.deg;

	delete[] this->coef;
	this->coef = new int[this->deg + 1];

	for (int i = 0; i <= this->deg; i++)
		this->coef[i] = B.coef[i];

	return *this;
}

void Polynom::setMemory(unsigned int deg) {
	delete[] this->coef;
	this->coef = new int[deg+1];
}

Polynom Polynom::operator*(const Polynom& B) {
	unsigned int deg_result;
	deg_result = this->deg + B.deg;

	Polynom result(deg_result);

	for(int i = 0; i <= this->deg; i++)
		for (int j = 0; j <= B.deg; j++)
		result.coef[i+j] = result.coef[i+j] + this->coef[i] * B.coef[j];

	result.correctDeg();

	return result;
}



Polynom sumOfPolynomials(const Polynom* array, const int N) {
	Polynom result;

	for (int i = 0; i < N; i++) {
		result = result + array[i];
	}
	return result;
}

std::ostream& operator << (std::ostream& os, const Polynom& B) {
	os << "Degree of the polynomial is " << B.getDeg() << endl;

	os << B.getCoef(0) << " " ;
	for (int i = 1; i <= B.getDeg(); i++)
		os << "+ (" << B.getCoef(i) << ")*x^" << i << " ";

	os << endl;
	return os;
}

void  Polynom::correctDeg() {
	for (int i = deg; i >= 0; i--)
		if (coef[i] == 0) {
			deg = deg - 1;

			int *new_coef = new int[deg + 1];

			for (int j = 0; j <= deg; j++)
				new_coef[j] = coef[j];

			delete[] coef;
			coef = new_coef;

		} else
			break;
}
