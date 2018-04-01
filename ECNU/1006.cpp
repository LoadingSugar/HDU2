#include<stdio.h>
using namespace std;
#define num 1000005
int prime[num];
int size;
bool mark[num];
void init1(){
	for(int i=2;i<num;i++)
		mark[i]=true;
	mark[1]=false;mark[2]=true;
	for(int i=2;i<num;i++){
		if(mark[i]==true){
			for(int j=i*2;j<=num;j+=i)
				mark[j]=false;
		}
	}
}
void init(){
	for(int i=2;i<num;i++)mark[i]=true;
	size=0;
	for(int i=2;i<num;i++){
		if(mark[i]==false)continue;
		prime[size++]=i;
		for(int j=i*2;j<num;j+=i){
			mark[j]=false;
		}
	}
}
int main(){
	init();
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		int t=0;
		for(int i=m;i<=n;i++){
			if(mark[i]==true)t++;
		}
		printf("%d\n",t);
	}
	return 0;
} 
