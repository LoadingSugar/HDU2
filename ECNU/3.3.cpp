#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<iostream> 
using namespace std;
priority_queue<int,vector<int>,greater<int> > Q;
int main(){
	int n;
	while(cin>>n){
		while(Q.empty()==false)Q.pop();
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			Q.push(x);
		}
		int ans=0;
		while(Q.size()>1){
			int a=Q.top();
			Q.pop();
			int b=Q.top();
			Q.pop();
			Q.push(a+b);
			ans+=(a+b);
		}
		cout<<ans;
	}
	return 0;
}
