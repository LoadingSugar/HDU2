#include<iostream>
#include<stdio.h> 
#include<string>
using namespace std;
int main(){
	string s;
	int n;
	while(cin>>n){
		getchar();
		getline(cin,s);
		for(int i=0;i<n;i++)
			cout<<s<<endl;
	}
	return 0; 
}
