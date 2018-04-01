#include<stdio.h>
#include<string.h>
#define MaxSize 100
char a[MaxSize][MaxSize];
void fun(char *s,char c){
	int num=strlen(s);
	int j=0,k=0;
	for(int i=0;i<num;i++){
		if(s[i]==c){
			a[j++][i]='\0';
			k=0;
		}
		else
			a[j][k++]=s[i];
	}
}
int main(){
	char l='1';
	int o=l;
	printf("%d\n",o);
	char s[100]="abbc,hkjlk,jkl,lklk,ljkkj"; 
	char c=',';
	fun(s,c);
	for(int i=0;i<5;i++){
		printf("%s\n",a[i]);
	}
	if(s[4]==c)printf("%d",strlen(s));
	return 0;
} 
