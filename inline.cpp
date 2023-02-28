#include <iostream>
using namespace std;

class Base{
public:
    inline virtual void who(){
        cout << "i am base\n";
    }
    virtual ~Base(){
        cout << "destructor of base\n";
    }
};

class Derived : public Base{
public:
    inline void who(){
        cout << "i am derived\n";
    }
    ~Derived(){
        cout << "destructor of derived\n";
    }
};

int main(){
    Base b;
    b.who();

    Base *ptr = new Derived();
    ptr->who();

    delete ptr;
    ptr = nullptr;

    return 0;
}