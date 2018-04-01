#include<stdio.h> 
#include<stack>
#include<iostream>
using namespace std;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int ans=1;
		while(b!=0){
			if(b%2==1){
				ans*=a;
				ans%=1000;
			}
			b/=2;
			a*=a;
			a%=1000;
		}
		cout<<ans<<endl;	
	} 
	return 0;
}
