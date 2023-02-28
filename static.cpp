#include <iostream>
using namespace std;

class apple{
public:
    static int appCount;
    int size;

    static void printMsg(){
        printf("%s\n","apple");
        printf("%d\n", appCount);
    }
    void printSize(){
        printf("%d\n", size);
        printf("%d\n", appCount);
    }
};

int apple::appCount = 0;

int main()
{
    apple::printMsg();

    apple app;
    app.size = 10;
    app.printSize();

    return 0;
}