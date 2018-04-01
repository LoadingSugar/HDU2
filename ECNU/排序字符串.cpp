#include<stdio.h> 
#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<vector> 
using namespace std;
vector<string> ans;
bool cmp(string a,string b){
	return a<b;
}
int main(){
	int n;
	string tmp;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			cin>>tmp;
			ans.push_back(tmp);
		}
		sort(ans.begin(),ans.end(),cmp);
		for(int i=0;i<n;i++){
			cout<<ans[i]<<endl; 
		} 
	}
	return 0;
}
