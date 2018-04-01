#include<stdio.h> 
int f(int a){
	static int x=1;
	return (x*=a);
}
int main(){
	int i,j;
	for(i=1;i<4;i++){
		j=3;
		switch(i){
			case 1:while(j){
			case 2:printf("i=%d,",i);
			case 3:printf("j=%d,",j--);
			default:;
			}
		}
		printf("\n");
	}
	//for(i=1;i<5;i++)printf("%d %d\n",i,f(i));	
}
