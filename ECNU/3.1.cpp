#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack>
#include<iostream> 
using namespace std;
stack<int> s;
char str[110],ans[110];
int main(){
	while(cin>>str){
		int i;
		for(i=0;str[i]!=0;i++){
			if(str[i]=='('){
				s.push(i);
				ans[i]=' ';
			}
			if(str[i]==')'){
				if(s.empty()==true)ans[i]='$';
				else {
					ans[i]=' ';
					s.pop();
				}
			}
			else{
				ans[i]=' ';
			}
		}
		while(s.empty()==false){
			ans[s.top()]='?';
			s.pop();
		}
		ans[i]=0;
		puts(ans);
	}
	return 0;
}
