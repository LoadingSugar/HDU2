#include<stdio.h>
#include<string.h> 
int main(){
	int a[10];//={0};
	printf("%d\n",sizeof(int));
	memset(a,10,10);
	for(int i=0;i<10;i++)
	printf("%d\n",a[i]);
} 
