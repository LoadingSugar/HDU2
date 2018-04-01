#include<stdio.h>
#include<stack> 
#include<queue>
#include <vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
	vector<int> v;
	for(int i=0;i<10;i++)
		v.push_back(i);
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
		printf("IT is %d\n",*it);
	char a[10]="hello";
	string name=a;
	string s="hello9",temp;
	s+=name;
	cin>>temp;
	s+=temp;
	cout<<s;
	return 0;	
}

