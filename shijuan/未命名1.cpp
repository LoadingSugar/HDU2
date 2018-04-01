#include<stdio.h>
int a[4];
int convert[32];
void fun(int n){
	int j=0;
	for(int i=31;i>=0;i--){
		printf("%d",n>>i&1);
		convert[j]=(n>>i&1);
		j++;
	}
	for(j=0;j<4;j++){
		int sum=0;
		for(int i=j*8;i<(j+1)*8;i++){
			sum*=2;
			sum+=convert[i];
		}
		a[j]=sum;
	}
}
int main(){
	fun(2);
	for(int i=0;i<4;i++)
	printf("\n%d\n",a[i]);
} 
