#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	 char a[50]="abcd"; const char c[5]="xyz";const char b[12]="hijk lmdn";
	char *p;
	printf("%s,%sǰ2���ַ��Ƿ����===>  ",a,b);
printf("%d\n",memcmp(a,b,2));//-1��ʾaС��b,0��� 
	//�Ƚ�a,bǰ3���ַ��Ĵ�С
	printf("���Ƚ�%s,%sǰ3���ַ��Ĵ�С===>  ",a,b);
int count=strncmp(a,b,3);printf("%d\n",count); 
	printf("��%s,%s��С===>  ",a,b);
int k=strcmp(a,b);printf("%d\n",k);//strncmp
	puts("=============================================");
	printf("��2���ַ��ظ����Ƶ�%s��===>  ",a);
memset(a,'b'-'\0',2);printf("%s\n",a);
	printf("��%s�ӵ�%s����===>  ",b,a);
strcat(a,b);printf("%s\n",a);//strncat
	printf("%s���Ƶ�%s��===>  ",b,a);//puts(b);puts(a);
strcpy(a,b); printf("%s\n",a);//strncpy
	puts("=============================================");
	printf("����ĳ�ַ���%s�е�һ�γ���λ��ָ��===>  ",b);		
p=strchr(b,'d'-'\0');printf("%c\n",*p);
	printf("���ҿո����/��%s�е�һ�γ��ֵ�λ��===>  ",b);
count=strcspn(b," /");printf("%d\n",count);//���ص��±꣬û���򷵻�\0�ڵ��±� 
	printf("����%s����===>  ",a);
count=strlen(a);printf("%d\n",count);//���Ȳ�����\0 
	//��cǰ�����ַ��ӵ�a����
	printf("��%cǰ�����ַ��ӵ�%s����===>  ",c,a);
strncat(a,c,2);printf("%s\n",a);
	int h='g';
	//���ش�д��ĸ
printf("%c\n",toupper(h)+'\0');
char s[6]="hello",t[6]="world";
char *r;r=(char*)malloc(strlen(s)+strlen(t)+1);//�ǵü�1 
strcpy(r,s);strcat(r,t); 
	return 1;
	
}
