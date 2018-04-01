#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	vector<int> V;
	int num,temp,n;
	while(cin>>num){
		temp=num;
		while(temp>0){
			cin>>n;
			V.push_back(n);
			temp--;
		}
		sort(V.begin(),V.end(),cmp);
		for(int i=0;i<V.size();i++)
			cout<<V[i]<<'\t';
		cout<<endl;
	}
	return 0;	
}
