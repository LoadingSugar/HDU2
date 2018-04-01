#include<stdio.h>
#define maxSize 100
char path[20];
int flag[3]={0};
char a[10]="ab1";
int book[20]={0};

void fun(int t,int k,int m){
	if(k==m){
		printf("%s\n",path);
		return;}
	for(int i=0;i<3;i++){
		if(flag[i]==0&&i>=t){
			flag[i]=1;
			path[k]=a[i];
			fun(i,k+1,m);
			flag[i]=0;
		}
	}	
}
void list(int m,int k,int j){
	if(k==m){
		printf("%s\n",path);
		return;}
	for(int i=0;i<3;++i){
		if(book[i]==0&&i>=j){
			path[k]=a[i];
			book[i]=1;
			list(m,k+1,i);
			book[i]=0;
		}
	}
}
int main(){
	
	//list(2,0,0);
	fun(0,0,2);
	//printf("%s\n",a) ;
	
}
