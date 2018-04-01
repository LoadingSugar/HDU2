#include<stdio.h> 
int otd(int *otc){
	 int dec=0;
	  char a[50]; 
	  sprintf(a,"%d",*otc);//10 格式化并打印各种数据到a
	  puts(a);
	   sscanf(a,"%o",&dec);//8输入到dec中 
	  puts(a);
	    return dec;
	}
void flot16(int n){
	if(n!=0){
		flot16(n/8);//flot16(n/16);
		printf("%d",n%8);//八进制//printf("%x",n%16)
	}
}
	int main(void){
	 int a=1898; 
	 /*保存一个八进制数字*/ int d=otd(&a); 
	 //printf("%d\n",a);
	   /*将a转换为十进制数字*/ printf("%d",d);
	   //flot16(a);
	   char k='z';
	  // printf("%d\n",k-'0'); 
	    return 0;}
	    
