#include<stdio.h> 
int otd(int *otc){
	 int dec=0;
	  char a[50]; 
	  sprintf(a,"%d",*otc);//10 ��ʽ������ӡ�������ݵ�a
	  puts(a);
	   sscanf(a,"%o",&dec);//8���뵽dec�� 
	  puts(a);
	    return dec;
	}
void flot16(int n){
	if(n!=0){
		flot16(n/8);//flot16(n/16);
		printf("%d",n%8);//�˽���//printf("%x",n%16)
	}
}
	int main(void){
	 int a=1898; 
	 /*����һ���˽�������*/ int d=otd(&a); 
	 //printf("%d\n",a);
	   /*��aת��Ϊʮ��������*/ printf("%d",d);
	   //flot16(a);
	   char k='z';
	  // printf("%d\n",k-'0'); 
	    return 0;}
	    
