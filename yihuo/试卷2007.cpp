#include<stdio.h> 
#include<string.h>
char *s(char **p,char *pn);
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
	
	return 1; 
}	
char *s(char **p,char *pn){
	for(;*p;++p)if(!strcmp(*p,pn))return *p;return (*p);
}
				