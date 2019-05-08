#include "fieldElement.h"

using namespace std;

FieldElement::FieldElement(int v, int p){
  if(v < 0 || v >= p){
    throw 1;
  }

  _v = v;
  _p = p;
}

FieldElement operator+(FieldElement &left, FieldElement &right){
  if(left._p != right._p){
    throw 2;
  }

  FieldElement res((left._v + right._v) % left._p, left._p);
  return res;
}

FieldElement operator-(FieldElement &left, FieldElement &right){
  // Operation only apply for field with the same order(?)
  if(left._p != right._p){
    throw 2;
  }

  return FieldElement((left._v - right._v) % left._p, left._p);
}

FieldElement operator*(FieldElement &left, FieldElement &right){
  if(left._p != right._p){
    throw 2;
  }

  return FieldElement((left._v * right._v) % left._p, left._p);
}

bool operator==(FieldElement &left, FieldElement &right){
  if(left._p == right._p && left._v == right._v){
    return true;
  }

  return false;
}

ostream & operator << (ostream &out, const FieldElement &f){
  out << "F(" << f._v << ")" << f._p;
  return out;
}
