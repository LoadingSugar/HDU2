#include<stdio.h> 
#include<stack>
#include<iostream>
using namespace std;
int prime[1010];
bool mark[1010];
int primeSize;
void init(){
	for(int i=1;i<1000;i++){
		mark[i]=false; 
	} 
	primeSize=0;
	for(int i=2;i<1000;i++){
		if(mark[i]==true)continue;
		else{
			prime[primeSize++]=i;
		}
		for(int j=i*i;j<=1000;j+=i){
			mark[j]=true;
		}
	}
}
int cnt[1010]={0};
int cnt2[1010]={0};
int main(){
	int n,a,k;
	init();
	cout<<"hello";
	while(scanf("%d%d",&n,&a)==2){
		
		for(int i=0;prime[i]<=n;i++){
			/*int t=n;
			while(t){
				cnt[i]+=t/prime[i];
				t=t/prime[i];
			}*/
			int key=prime[i];
			while(key<=n){
				cnt[i]+=(n/key);
				key*=prime[i];
			}
		
		}
		int ans=12312;
		for(int i=0;prime[i]<=a;i++){
			while(a%prime[i]==0){
				cnt2[i]++;
				a/=prime[i];
			}
			if(cnt2[i]==0)continue;
			if((cnt[i]/cnt2[i])<ans)ans=cnt[i]/cnt2[i]; 
		}
		cout<<ans;
	}
	return 0;
}
