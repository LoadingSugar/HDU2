#include<stdio.h> 
#define maxSize 50
int BaseTrans(int x){
	int result;
	int stack[maxSize],top=-1;
	while(x){
		stack[++top]=x%2;
		x=x/2;
	}
	while(top!=-1){
		result*=10;
		result+=stack[top--];
	}
	return result;
}
int main(){
	printf("%d\n",BaseTrans(1));
	return 1;
}
