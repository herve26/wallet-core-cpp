#include <iostream>

#include "fieldElement.h"

using namespace std;

int main() {
    FieldElement f(2, 3);
    FieldElement g(1, 3);
    cout << f << endl << g << endl;
    cout << f + g << endl;
    if(f == g){
        cout << f << " equal " << g << endl;
    }
    else{
      cout << "not equal" << endl;
    }
}
