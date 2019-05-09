#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point{
  public:
    Point(int x, int y, int a, int b);
    Point(int a, int b);
    friend bool operator==(const Point &left, const Point &right);
    friend bool operator!=(const Point &left, const Point &right);
    friend Point operator+(const Point &left, const Point &right);
    friend std::ostream & operator << (std::ostream &out, const Point &p);

private:
  int raise(int value, int expon);

  private:
    int _x;
    int _y;
    int _a;
    int _b;
    bool _inf = false;
};

#endif
