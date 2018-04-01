#include<iostream>
#include<stdio.h> 
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> st;
int num;
int main(){
	string s,ans;
	st.push_back("0");
	st.push_back("01");
//	vector<string>::iterator it1=st.end();
	//printf("%d",(*it1).size());
	for(int i=0;i<20;i++){
		num=st.size();
		s=st[num-1];
		for(int j=0;j<s.size();j++){
			if(s[j]=='0')s[j]='1';
			else s[j]='0';
		}
		//reverse(s.begin(),s.end());
		ans=st[num-1]+s;
		//cout<<ans<<endl;
		st.push_back(ans);
	}
	int n; 
	while(cin>>n){
		cout<<st[n]<<endl;
	} 
	return 0;
} 
