#include<stdio.h>
#include<string.h>
#define nmemb 3
	typedef struct test
	{
	char name[4];
	int size;
	};
	test s[nmemb];
	test t[nmemb];
int main(){
	//s[0].name="tom";
	strcpy(s[0].name,"Tomt");
	s[0].size=1;
	strcpy(s[1].name,"Catt");
	s[1].size=2;
	strcpy(s[2].name,"Kett");
	s[2].size=3;
	FILE * stream,*fp;
	int i;
	stream = fopen("D:\\Code\\yan\\file\\test\\3.txt","w");
	fp = fopen("D:\\Code\\yan\\file\\test\\3.txt","r");
	fwrite(s,sizeof(struct test),nmemb,stream);//向文件写入一个数据块 
	fread(t,sizeof(struct test),nmemb,fp);
	for(int i=0;i<nmemb;i++){
		printf("%d,%s==%d\n",i,t[i].name,t[i].size);
	}
	fclose(stream);
	
}
