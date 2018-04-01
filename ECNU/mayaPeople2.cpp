#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<string>
using namespace std;
char a[10001];
char b[]="2012";
int size=0;
int k;
struct node{
	char str[10001];
	int size;
};
queue<node> q;
map<string,int> m;
char *find(char *str,char *str2){
	char *p;
	p=strstr(str,str2);
	return p;
}
int  bfs(){
	while(!q.empty()){
		node no=q.front();
		q.pop();
		if(find(no.str,b)!=NULL)return no.size;
		for(int i=0;i+1<k;i++){
			char str2[10001];
			strcpy(str2,no.str);
			char temp=str2[i];
			str2[i]=str2[i+1];
			str2[i+1]=temp;
			//puts(str2);
			if(m.find(str2)==m.end()){
				node no2;
				strcpy(no2.str,str2);
				no2.size=no.size+1;
				q.push(no2);
				m[str2]=size++;
			}
		}
	}
	return -1;
}
int main(){
	while(scanf("%d",&k)!=EOF){
		scanf("%s",a);
		
		while(!q.empty())q.pop();
		m.clear();
		size=0;
		node no2;
		no2.size=0;strcpy(no2.str,a);
		q.push(no2);
		m[no2.str]=size++;
		int t=bfs();
		printf("%d\n",t);	
	}
	return 0;
} 

