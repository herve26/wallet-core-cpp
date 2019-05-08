#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

#include <ostream>

class FieldElement{
  public:
    FieldElement(int v, int p);
    friend FieldElement operator+(FieldElement &left, FieldElement &right);
    friend FieldElement operator-(FieldElement &left, FieldElement &right);
    friend FieldElement operator*(FieldElement &left, Fieldelement &right);
    friend bool operator==(FieldElement &left, FieldElement &right);
    friend std::ostream & operator << (std::ostream &out, const FieldElement &f);
  private:
    int _v;
    int _p;
};

#endif
