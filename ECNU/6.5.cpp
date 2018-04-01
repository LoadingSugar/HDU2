#include<stdio.h> 
#include<stack>
#include<iostream>
#include<queue>
using namespace std;
int n;
int ans[22];
bool hash[22];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
bool judge(int x){
	for(int i=0;i<13;i++){
		if(prime[i]==x)return true;
	}
	return false;
}
void check(){
	if(judge(ans[1]+ans[n])==false)return;
	for(int i=1;i<=n;i++){
		if(i!=1)cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
}
void dfs(int num){
	if(num>1)
		if(judge(ans[num]+ans[num-1])==false)return;
	if(num==n){check();return;}
	for(int i=2;i<=n;i++){
		if(hash[i]==false){
			ans[num+1]=i;
			hash[i]=true;
			dfs(num+1);
			hash[i]=false; 
		}
	}
}
int main(){
	while(scanf("%d",&n)){
		for(int i=0;i<22;i++)hash[i]=false;
		hash[1]=true;
		ans[1]=1;
		dfs(1);
		cout<<endl;
	}
	return 0;
}
