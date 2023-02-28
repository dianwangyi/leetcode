#include <iostream>

using namespace std;

class Test1{
public:
    Test1(int n):m_num(n){};
    inline int getM(){return m_num;};
private:
    int m_num;
};

class Test2{
public:
    explicit Test2(int n):m_num(n){};
    inline int getM(){return m_num;}
private:
    int m_num;
};

int main(){
    Test1 t1(1);
    printf("t1 = %d\n", t1.getM());
    
    Test2 t2(2);
    printf("t2 = %d\n", t2.getM());
    
    Test1 t3 = 3;
    printf("t3 = %d\n", t3.getM());

    Test2 t4 = 4;

    return 0;
}