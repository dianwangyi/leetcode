#include <iostream>

using namespace std;

int main()
{
    const int num = 0;
    int i = 0;
    // int * const ptr = &num;
    const int * const ptr = &num;
    int * const ptri = &i;
    // *(ptri) ++;
    int *ptri1 = &i;
    *(ptri1) ++;
}

