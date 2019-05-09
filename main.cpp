#include <iostream>

#include "fieldElement.h"
#include "point.h"

using namespace std;

int main() {
    FieldElement f(2, 19);
    FieldElement g(7, 19);
    cout << f << endl << g << endl;
    cout << f + g << endl;
    cout << f.pow(3) << endl;
    cout << f / g << endl;
    if(f == g){
        cout << f << " equal " << g << endl;
    }
    else{
      cout << "not equal" << endl;
    }

    cout << "======== POINT =======" << endl;

    Point p1(3, 7, 5, 7);
    Point p2(-1, -1, 5, 7);
    cout << p1 + p2 << endl;
    cout << p2 + p2 << endl;
    cout << p1 << endl;
    if(p1 != p2){
      cout << p1 << " not equal " << p2 << endl;
    }
    else{
      cout << p1 << " equal " << p2 << endl;
    }

    cout << "======= ECC OVER FiELD ======" << endl;
    FieldElement a(0, 223);
    FieldElement b(7, 223);
    FieldElement x(192, 223);
    FieldElement y(105, 223);
    Point p(x, y, a, b);
    cout << p << endl;
}
