#include<stdio.h>
int sum=0;
int a[3];
void list(int n,int i){
	if(i==n){
		sum++;
		for(int j=0;j<n;j++)printf("%d",a[j]);
		printf("\n");
		return;
	}
	a[i]=0;
	list(n,i+1);
	a[i]=1;
	list(n,i+1);
} 
void list2(int n,int i){
	if(i==n){
		sum++;
		for(int j=0;j<n;j++)printf("%d",a[j]);
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++){
		
	}
	a[i]=0;
	list(n,i+1);
	a[i]=1;
	list(n,i+1);
} 

int main(){
	
	list(3,0);
	printf("hello-%d",sum);
} 
