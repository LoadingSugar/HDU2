#include<stdio.h>
int main(){
	int x=-2;
	for(int i=31;i>=0;i--)
		printf("%d",x>>i&1); 
	printf("\n");
	int j=11;
	j>>=3;
	
	printf("%d\n",j&1);
}
