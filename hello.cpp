#include <graphics.h>
#include <conio.h>
 
int main()
{
	initgraph(640, 480);
	circle(320, 240, 100);
	getch();
	closegraph();
	return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     cout << "Hello, world!" << endl;
//     cout << "����һ����򵥵�C++����" << endl;

//     system("pause");
//     return 0;
// }


// #include <stdio.h>
// #include <string.h>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// void toArray(int n, int N[]){
//     for(int i = 0; i < 4; i++)
//     {
//         N[i] = n % 10;
//         n /=  10;
//     }
// }
// int toNumber(int N[]){
//     int n = 0;
//     // n = pow(10,3);
//     for(int i = 0; i < 4; i++){
//         n = n * 10 + N[i];
//     }
//     return n;
// }

// bool cmp(const int &l, const int &r){
//     return l > r;
// }

// // int main(){
// //     int n, min, max;
// //     scanf("%d", &n);
// //     int N[4] ={0};
// //     while(1){
// //         toArray(n, N);
// //         sort(N, N + 4);
// //         min = toNumber(N);
// //         sort(N, N + 4, cmp);
// //         max = toNumber(N);
// //         n = max - min;
// //         printf("%04d - %04d = %04d\n", max, min, n); 
// //         // %4d ����4λ��ȣ��Ҷ��룬�������߲��ո� %04d ͬ �������߲�0 %.4d ����4λС��
// //         if(n == 0 || n == 6174) break;
// //     }

// //     return 0;
// // }

// // # include <stdio.h>
// // int main(void)
// // {
// //     char str[30];
// //     char *string = str;  //һ��Ҫ�Ƚ�ָ�������ʼ��
// //     printf("�������ַ�����");
// //     gets(string);  //Ҳ����д��gets(str);
// //     printf("%s\n", string);  //����������Ѿ�����õġ�ָ���������
// //     return 0;
// // }