#include<stdio.h> 
#include<stack>
#include<iostream>
using namespace std;
int main(){
	int n,m,ans,num;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			cin>>m;
			ans=1;
			for(int i=2;i*i<=m;i++){
				num=0;
				while(m%i==0){
					num++;
					m=m/i; 
				}
				if(num>0){
					num++;
					ans=ans*num;
				}			
			}
			if(m>1)ans=ans*2;
			cout<<ans<<endl;
		} 
	}
	return 0;
}
