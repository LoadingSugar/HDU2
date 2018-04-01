#include<stdio.h> 
void fun1(int n) {
	if(n==0){//在二进制前面多加了一个0 
		printf("%d",n);return;
	}
	if(n>0){
		fun1(n/2);
		printf("%d",n%2);
	}
}
int  judge(int k[],int a[],int b[],int c[]){
	int x1=0,x2=0,x3=0;
	for(int i=0;i<10;i++){
		if(k[i]==a[i])x1++;
		if(k[i]==b[i])x2++;
		if(k[i]==c[i])x3++;
	}
	if(x1==7&&x2==7&&x3==7)return 1;
	else return 0;
} 
void test(int k[],int a[],int b[],int c[],int n){
	if(n==0&&judge(k,a,b,c))for(int i=0;i<10;i++)printf("%d",k[i]) ;
	else if(n<10){
		k[n]=0;
		test(k,a,b,c,n+1);
		n--;
		k[n]=1;
		test(k,a,b,c,n+1);
		n--;
	}

}
int main(){
	//fun1(0);
	int k[10]={0},a[10]={0,1,1,1,0,1,0,0,1,0},b[10]={0,0,1,1,1,0,1,1,0,0},c[10]={1,0,1,0,1,1,1,0,1,1};
	test(k,a,b,c,0);
	return 1;
}
