#include <iostream>

using namespace std;

int main()
{
    int a = 0x1234;
    printf("%d\n", sizeof(a));

    char b = (char)(a);
    printf("%d\n", sizeof(b));

    if(b == 0x12)
        cout << "big endian" << endl;
    else if(b == 0x34)
        cout << "little endian" << endl;

    return 0; 

}