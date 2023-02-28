#include <iostream>

using namespace std;

class O{
public:
    O(){
        cout << "constructor O" << endl; 
    }
    ~O(){
        cout << "deconstructor o" << endl;
    }
};

class A:O{
    public:
    A(){
        cout << "constructor A" << endl;
    }
    ~A(){
        cout << "deconstructor A" << endl;
    }
};

class B{
    public:
    B(){
        cout << "constructor B" << endl;
    }
    ~B(){
        cout << "deconstructor B" << endl;
    }
};

class D{
    public:
    D(){
        cout << "constructor D" << endl;
    }
    ~D(){
        cout << "deconstructor D" << endl;
    }
};

class E{
    public:
    E(){
        cout << "constructor E" << endl;
    }
    ~E(){
        cout << "deconstructor E" << endl;
    }
};

class Test:E,D{
    B b;
    A a;
    public:
    Test(){
        cout << "constructor Test" << endl;
    }
    ~Test(){
        cout << "deconstructor Test" << endl;
    }
};

int main()
{
    Test* t = new Test;
    delete t;

    system("pause");
    return 0;
}

