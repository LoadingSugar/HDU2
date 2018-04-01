#include<stdio.h>
#include<iostream>
using namespace std;
int check(int x){
	int sum=0;
	for(int i=1;i<x;i++){
		if(x%i==0)sum+=i;
	}
	if(sum==x)return 1;
	if(sum>x)return 2;
	else return 0;
}
int main(){
	int a[60],b[60],an=0,bn=0;
	for(int i=2;i<=60;i++){
		if(check(i)==1)a[an++]=i;
		if(check(i)==2)b[bn++]=i;
	}
	printf("E: ");
	for(int i=0;i<an-1;i++)
	printf("%d ",a[i]);printf("%d",a[an-1]);
	cout<<endl;
	printf("G: ");
	for(int i=0;i<bn-1;i++)
	printf("%d ",b[i]);printf("%d",b[bn-1]);
	cout<<endl;
	return 0;
} 
