#include <string.h>
#include <iostream>

using namespace std;

int main(){

    const char* str = "name";

    printf("%d\n", sizeof(str));
    printf("%d\n", strlen(str));

    return 0;

}