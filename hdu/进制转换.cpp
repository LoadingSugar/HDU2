#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
long  toTen(char a[], int bit)
         {
             int length = strlen(a);
             int i, b = 1, sum = 0; //i要做数组a的下标，注意其起止范围
             for (i = length - 1; i >= 0; i--)
                 {
                     if (a[i] >= 'A')
                         {
                             sum += (a[i] - 'A' + 10) *b;
                             b *= bit;
                         }
                     else
                         {
                             sum += (a[i] - '0') *b;
                             b *= bit;
                         }
                 }
             return sum;
         }
int main()
{
    char s1[] = "E";
    int a = toTen(s1, 16);
    cout << a << endl;
    char temp[200];
    int b= 15;
    _itoa(a, temp, 16);
    cout << temp;

    system("pause");
    return 0;
}
