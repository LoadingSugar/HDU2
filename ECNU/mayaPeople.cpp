#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
	char a[10001];
	char b[]="2012";
	int  ftmp=0;
	bool f=0;
	int k;
	int c=0;
char *find(char *str,char *str2){
	char *p;
	p=strstr(str,str2);
	return p;
}
void dfs(int n){
	if(find(a,b)!=NULL)
	{f=1;
	c=ftmp;
	return;}
	if((n+1)>=k)return ;
	char temp=a[n];
	a[n]=a[n+1];
	a[n+1]=temp;
	ftmp++;
	dfs(n+1);
	ftmp--;
}
int main(){
	while(scanf("%d",&k)!=EOF){
		scanf("%s",a);
		dfs(0);
		if(f==false)printf("%d\n",-1);	
		else printf("%d\n",c);
	}
	return 0;
} 

