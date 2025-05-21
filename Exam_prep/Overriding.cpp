#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() {  // overrides Base::show()
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Derived obj;
    Base obj1;
    obj1.show();
    obj.show();  // Calls Derived's version
}
