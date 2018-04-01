#include<algorithm>
#include<string.h>
#include<stdio.h>
#define MAX 1001
using namespace std;
int last,n,v[MAX],ans;
int count(int dep){
	int sum=0;
	for(int i=dep;i<n;i++)sum+=v[i];
	return sum;
}
void  dfs(int dep,int val,int num){
	if(val==last){ans=min(ans,num);return;}
	if(val+count(dep)<last)return;
	if(dep>n-1)return;
	dfs(dep+1,val,num);
	if(dep<n-1&&val<last)dfs(dep+1,val+v[dep+1],num+1);
}

/*5
void  dfs(int dep,int val,int num){
	if(val==last){ans=min(ans,num);return;}
	for(int i=dep+1;i<n;i++)
		dfs(i,val+v[i],num+1);
}*/
int main(){
	while(scanf("%d%d",&last,&n)!=EOF){
		memset(v,0,sizeof(v));
		ans=1000;
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		dfs(-1,0,0);
		if(ans!=1000)printf("%d",ans);
		else printf("%d",0);
	}
	return 0; 
}

