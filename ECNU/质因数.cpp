#include<stdio.h> 
#include<stack>
#include<iostream>
using namespace std;
int main(){
	int n,m,num;
	while(cin>>m){
			num=0;
			for(int i=2;i*i<=m;i++){
				while(m%i==0){
					num++;
					m=m/i; 	
				}	
			}
			if(m>1)num++;
			cout<<num<<endl;
	}
	return 0;
}
