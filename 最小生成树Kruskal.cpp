#include<stdio.h>
#include<algorithm>
#define maxSize 50
typedef struct Road{
	int a,b;
	int w;
	bool operator <(const Road &A)const{
		return w<A.w;
	} 
}Road;

int v[9];
int getRoot(int p){
	while(p!=v[p])p=v[p];
	return p;
} 
void Kruskal(Road r[],int n,int e,int &sum){
	int a,b;
	sum=0;
	for(int i=0;i<n;i++)
		v[i]=i;
	std::sort(r,r+e);
	for(int i=0;i<e;i++)
		printf("%d\t",r[i].w);
	for(int i=0;i<e;i++){
		a=getRoot(r[i].a);
		b=getRoot(r[i].b);
		if(a!=b){
			v[a]=b;
			sum+=r[i].w;
		}
	}
}
int main(){
	Road r[9];
	r[0].a=0,r[0].b=1,r[0].w=1,r[1].a=0,r[1].b=2,r[1].w=5;
	r[2].a=0,r[2].b=3,r[2].w=6,r[3].a=1,r[3].b=2,r[3].w=8;
	r[4].a=2,r[4].b=3,r[4].w=7,r[5].a=1,r[5].b=4,r[5].w=4;
	r[6].a=2,r[6].b=4,r[6].w=2,r[7].a=4,r[7].b=5,r[7].w=9;
	r[8].a=3,r[8].b=5,r[8].w=3;
	int sum=0;
	Kruskal(r,6,9,sum);
	puts("----------------");
	printf("%d",sum);
	return 1;
}
