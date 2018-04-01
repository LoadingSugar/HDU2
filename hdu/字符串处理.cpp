#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string a;
    string b;
    string c[10];
    getline( cin ,a);
   // scanf("%[^s]",a);
    int t,i=0;
    b=a;
    while(b.length()!=0&&t!=string::npos){
        t=b.find(' ');
        c[i++]=b.substr(0,t);
        b=b.substr(t+1,b.length()-t-1);
        printf("%s\n",c[i-1].data());
    }
    for(int j=0;j<i;j++)
        printf("%s\n",c[j].data());
    return 0;
}
