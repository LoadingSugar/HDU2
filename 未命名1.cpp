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
	//a,bǰ�����ַ��Ƿ����
	memcmp(a,b,2);
	//��2���ַ��ظ����Ƶ�a��
	//void *memset(void *str, int c, size_t n)
	//�����ַ� c��һ���޷����ַ��������� str ��ָ����ַ�����ǰ n ���ַ���
	memset(a,'b'-'\0',2);
	//��b�ӵ�a����
	strcat(a,b);
			for(int i=0;*(a+i)!='\0';i++)
				printf("%c",a[i]);
			printf("\n");
			printf("%s",a);//��¥�������ͬ 
			printf("\n");
	//����ĳ�ַ���b�е�һ�γ���λ��ָ��
	p=strchr(b,'d'-'\0');
			printf("%c\n",p);
	//�Ƚ�a,b��С��a>b����1
	int k=strcmp(a,b);
			printf("%d\n",k);
	//b���Ƶ�a��
	strcpy(a,b);
			for(int i=0;*(a+i)!='\0';i++)
				printf("%c",a[i]);
			printf("\n");
	//���ҿո����/��b�е�һ�γ��ֵ�λ��
	int count=strcspn(b," /");
			printf("%d\n",count);
	//���س���
	count=strlen(a);
			printf("%d\n",count);
	//��cǰ�����ַ��ӵ�a����
	strncat(a,c,2);
			for(int i=0;*(a+i)!='\0';i++)
						printf("%c",a[i]);
					printf("\n");
	//�Ƚ�a,bǰ3���ַ��Ĵ�С
	count=strncmp(a,b,3);
				printf("%d\n",count);
	int h='g';
	//���ش�д��ĸ
	printf("%c\n",toupper(h)+'\0');
	//printf(type(a));
	return 1;
}
