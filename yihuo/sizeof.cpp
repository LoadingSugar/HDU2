#include<stdio.h> 
#include<string.h>
#define N 10 
#define LEN 81 
char *s(char **p,char *pn);
int fun2(){
	//fun1(0);
	char st[N][LEN]; 
	int k[10]={0},a[10]={0,1,1,1,0,1,0,0,1,0},b[10]={0,0,1,1,1,0,1,1,0,0},c[10]={1,0,1,0,1,1,1,0,1,1};
	int t=sizeof(int [10]);//40 
	t=sizeof(int *[10]);//80,10个指针 
	t=sizeof(int (*)[10]);//8,一个指针8位 
	t=sizeof(int *());//1，函数指针所指向的函数 
	printf("%d\n",t);
	return 1;
}
int main(){
	//int a[4];
//	char *p;
//	short i;
//	bool b=(!(-1));
//	printf("%d\n",b);
//	char *c[]={"hello","world","heihei"};
//	char **q=c;
//	printf("%s\n",(*q));
//	printf("%d\n",sizeof((*q)));
	//char *ap[]={"hi","HZ0755","AB","BJ01"};
	char  i,*r=NULL,*a[]={"BJ01","Sh02-1","C","HZ0755",0};
	char *ap[]={"hi","HZ0755","AB","BJ01"};
	for(i=1;i<4;i++){
		r=s(a,ap[i]);
		if(r)printf("founded %s\n",r);
		else printf("unfounded %s\n",ap[i]);
	}
	fun2();
	return 1; 
}	
char *s(char **p,char *pn){
	for(;*p;++p)if(!strcmp(*p,pn))return *p;return (*p);
}

