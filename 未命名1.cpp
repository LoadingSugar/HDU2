#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	 char a[50]="basghjhg";
	 const char c[5]="sad";
	const char b[12]="agsa dja/nd";
	if(c[3]=='\0')puts("hhhhhhhhhhhhhhhhhhhhhhhhhhh") ;
	printf("\n");
	char *p;
	//a,b前几个字符是否相等
	memcmp(a,b,2);
	//将2个字符重复复制到a中
	//void *memset(void *str, int c, size_t n)
	//复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。
	memset(a,'b'-'\0',2);
	//将b接到a后面
	strcat(a,b);
			for(int i=0;*(a+i)!='\0';i++)
				printf("%c",a[i]);
			printf("\n");
			printf("%s",a);//与楼上输出相同 
			printf("\n");
	//查找某字符在b中第一次出现位置指针
	p=strchr(b,'d'-'\0');
			printf("%c\n",p);
	//比较a,b大小，a>b返回1
	int k=strcmp(a,b);
			printf("%d\n",k);
	//b复制到a中
	strcpy(a,b);
			for(int i=0;*(a+i)!='\0';i++)
				printf("%c",a[i]);
			printf("\n");
	//查找空格或者/在b中第一次出现的位置
	int count=strcspn(b," /");
			printf("%d\n",count);
	//返回长度
	count=strlen(a);
			printf("%d\n",count);
	//将c前两个字符接到a后面
	strncat(a,c,2);
			for(int i=0;*(a+i)!='\0';i++)
						printf("%c",a[i]);
					printf("\n");
	//比较a,b前3个字符的大小
	count=strncmp(a,b,3);
				printf("%d\n",count);
	int h='g';
	//返回大写字母
	printf("%c\n",toupper(h)+'\0');
	//printf(type(a));
	return 1;
}
