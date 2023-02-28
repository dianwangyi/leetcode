#include <stdio.h>

int gcd(int a, int b){
    if(b == 0) return a;

    int ret = gcd(b, a % b);
    return ret;
}

// int main(){
//     int num1, num2;
//     while(scanf("%d%d", &num1, &num2) != EOF){
//         printf("res = %d\n", gcd(num1, num2));
//     }
//     return 0;
// }