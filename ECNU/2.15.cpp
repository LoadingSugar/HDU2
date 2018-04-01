#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string>
#include<iostream> 
using namespace std;
struct program{
	int s;
	int e;
	bool operator <(const program &A) const{
		return e<A.e;
	} 
}buf[100];
int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<n;i++){
			scanf("%d%d",&buf[i].s,&buf[i].e); 
		}
		sort(buf,buf+n);
		int currenttime=0,ans=0;
		for(int i=0;i<n;i++){
			if(currenttime<=buf[i].s){
				currenttime=buf[i].e;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
