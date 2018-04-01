#include<stdio.h> 
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main(){
	string a="bananahello";
	string b="hello";
	int start=7;
	int temp=a.find(b,start);
	cout<<temp<<endl<<start<<endl;
	return 0;
}
