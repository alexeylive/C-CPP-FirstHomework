#include <iostream>
using namespace std;
#include "polinom.hpp"

Polinom::Polinom():
deg(0)
{
  this->coef = new int[1];
  this->coef = 0;
}

Polinom::correctDeg() {


}

Polinom::Polinom(const unsigned int deg, const int* coef)
deg(deg)
{
  this->coef = new int[this->deg];

  for (int i = 0; i < this->deg; i++)
    this->coef[i] = coef[i];
}

Polinom::Polinom(const Polinom& rhs):
deg(rhs.deg)
{
  this->coef = new int[deg];

  for (int i = 0; i < deg; i++)
    this->coef[i] = rhs.coef[i];
}

Polinom::Polinom() {
  delete[] coef;
}

Polinom Polinom::operator + (const Polinom& B) const {
  if (this->deg == B.deg) {
    
  }

  if (this->deg > B.deg)
    Polinom A(*this);

}
