#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	 char a[50]="abcd"; const char c[5]="xyz";const char b[12]="hijk lmdn";
	char *p;
	printf("%s,%s前2个字符是否相等===>  ",a,b);
printf("%d\n",memcmp(a,b,2));//-1表示a小于b,0相等 
	//比较a,b前3个字符的大小
	printf("将比较%s,%s前3个字符的大小===>  ",a,b);
int count=strncmp(a,b,3);printf("%d\n",count); 
	printf("较%s,%s大小===>  ",a,b);
int k=strcmp(a,b);printf("%d\n",k);//strncmp
	puts("=============================================");
	printf("将2个字符重复复制到%s中===>  ",a);
memset(a,'b'-'\0',2);printf("%s\n",a);
	printf("将%s接到%s后面===>  ",b,a);
strcat(a,b);printf("%s\n",a);//strncat
	printf("%s复制到%s中===>  ",b,a);//puts(b);puts(a);
strcpy(a,b); printf("%s\n",a);//strncpy
	puts("=============================================");
	printf("查找某字符在%s中第一次出现位置指针===>  ",b);		
p=strchr(b,'d'-'\0');printf("%c\n",*p);
	printf("查找空格或者/在%s中第一次出现的位置===>  ",b);
count=strcspn(b," /");printf("%d\n",count);//返回的下标，没有则返回\0在的下标 
	printf("返回%s长度===>  ",a);
count=strlen(a);printf("%d\n",count);//长度不计算\0 
	//将c前两个字符接到a后面
	printf("将%c前两个字符接到%s后面===>  ",c,a);
strncat(a,c,2);printf("%s\n",a);
	int h='g';
	//返回大写字母
printf("%c\n",toupper(h)+'\0');
char s[6]="hello",t[6]="world";
char *r;r=(char*)malloc(strlen(s)+strlen(t)+1);//记得加1 
strcpy(r,s);strcat(r,t); 
	return 1;
	
}
