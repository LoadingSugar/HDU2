#include<stdio.h>
int a[20];
int sum=0;
void list(int n,int i){
	if(i==n){
	++sum;
	return;
	}
	a[i]=0;
	list(n,i+1);
//	if(a[i-2]==0||a[i-1]==1){
	a[i]=1;
	list(n,i+1);
//	}
} 
int main(){
	int n;
	scanf("%d",&n);
	list(n,0);
	printf("%d",sum);
	return 0;
}
