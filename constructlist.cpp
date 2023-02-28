#include <iostream>

using namespace std;

struct Demo{
    const int m_a;
    int &m_b;

    Demo(int a, int b):m_a(a),m_b(b){};
    ~Demo(){};
};

int main(){
    Demo d(1,2);
    cout << d.m_a << endl;
    cout << d.m_b << endl;

    system("pause");
    return 0;
}