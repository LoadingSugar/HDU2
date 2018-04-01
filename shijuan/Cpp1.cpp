#include<stdio.h>
int f(char s[],int n){
	int i,k,v;char *p,*q;
	//q=s+n-1;
	//printf("%d\n",*q>>7);
	for(k=0,p=s,q=s+n-1;p<=q;++p,--q)
		for(i=0;i<8;++i,++k)
			if((v=(*p>>(7-i)&i))!=(*q>>i&1))return (0);
			else if(v)printf("k=%d\n",k);
	return (1);
}
int main(){
	char s[3]={16,24,8};
	
	int a=11;
	int j=a>>1&1;
	int i,k;
	for(i=0,k=0;i<10;k++,i++)
		a++;
	
	//printf("%d\n",s[1]);
	printf("f=%d\n",f(s,3));
} 