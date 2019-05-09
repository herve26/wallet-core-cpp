#include "point.h"

#include <iostream>
#include <cmath>

using namespace std;

Point::Point(int x, int y, int a, int b){
  _x = x;
  _y = y;
  _a = a;
  _b = b;
  int leftside = raise(_y, 2);
  int rightside = raise(_x, 3) + _a * _x + _b;

  if(leftside != rightside){
    throw 3;
  }
}

Point::Point(int a, int b){
  _x = 0;
  _y = 0;
  _a = a;
  _b = b;
  _inf = true;
}

bool operator==(const Point &left, const Point &right){
  if(left._x == right._x && left._y == right._y && left._a == right._a && left._b == right._b){
    return true;
  }

  return false;
}

bool operator!=(const Point &left, const Point &right){
  if(left == right){
    return false;
  }
  return true;
}

Point operator+(const Point &left, const Point &right){
  if(left._a != right._a || left._b != right._b){
    throw 4;
  }

  // Adding a point with a point at the infinity
  if(left._inf){
    return right;
  }

  if(right._inf){
    return left;
  }


  // If the two points are opposite each other on the x-asis
  if(left._x == right._x && left._y != right._y){
    return Point(left._a, left._b);
  }

  // When the two points intercept with a third point
  if(left._x != right._x){
    double s = (double)(right._y - left._y) / (double)(right._x - left._x);
    double x3 = pow(s, 2.0) - left._x - right._x;
    double y3 = s * (left._x - x3) - left._y;

    return Point((int)x3, (int)y3, left._a, left._b);
  }

  //
  if(left == right && left._y == 0){
    return Point(left._a, left._b);
  }

  // When the two points are equal
  if(left == right){
    double s = (double)(3 * left._x * left._x + left._a) / (double)(2 * left._y);
    double x3 = pow(s, 2.0) - (2 * left._x);
    double y3 = s * (left._x - x3) - left._y;

    return Point((int)x3, (int)y3, left._a, left._b);
  }

  throw 5;
}

int Point::raise(int value, int expon){
  int v = 1;
  for(int i=0; i < expon; i++){
    v *= value;
  }

  return v;
}


ostream & operator << (ostream &out, const Point &p){
  out << "x:" << p._x << " y:" << p._y << " a:" << p._a << " b:" << p._b;
  return out;
}
