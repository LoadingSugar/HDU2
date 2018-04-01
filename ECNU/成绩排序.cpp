#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<iostream> 
using namespace std;
typedef pair<string,int> pa;
bool comp(const pa &a,const pa &b){
	return a.second<b.second;
}
bool comp2(const pa &a,const pa &b){
	return a.second>b.second;
}
int main(){
	int n,flag,num;
    char c[10];
    while(cin>>n>>flag){ 
    vector<pa> Q;
        while(n>0){
            cin>>c>>num;
            Q.push_back(make_pair(c,num));
            n--;
        }
        if(flag) 
        	stable_sort(Q.begin(),Q.end(),comp) ;
        else
    		stable_sort(Q.begin(),Q.end(),comp2) ;
      for(int i=0;i<Q.size();i++){
            pa temp=Q[i];
            cout<<temp.first<<' '<<temp.second<<endl;
        }
      }
    return 0;
}
