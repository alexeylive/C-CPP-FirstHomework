#ifndef _POLINOM_HPP_
#define _POLINOM_HPP_

class Polinom{
public:
  Polinom();
  Polinom(const Polinom& rhs);
  Polinom(const unsigned int deg, const int* coef);
  ~Polinom();
  Polinom operator + (const Polinom& B) const;
private:
  unsigned int deg;
  int* coef;
  correctDeg();
}


#endif
