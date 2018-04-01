#include<stdio.h> 
#include<stack>
#include<iostream>
using namespace std;
#define N 1000
int Tree[N];
int findroot(int x){
	if(Tree[x]==-1)return x;
	else{
		int temp=findroot(Tree[x]);
		Tree[x]=temp;
		return temp; 
	}
} 
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		for(int i=0;i<n;i++)Tree[i]=-1;
		while(m--!=0){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findroot(a);
			b=findroot(b);
			if(a!=b)Tree[a]=b;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(Tree[i]==-1)ans++;
		}
		cout<<ans-1<<endl;
	}
}
