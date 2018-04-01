#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
void swap(char *a,char *b){
	char t=*a;*a=*b;*b=t;
}
void fun(char *a,int begin,int end){
	int i;
	if(begin==end)printf("%s\n",a);
	else{
		for(i=begin;i<=end;i++){
			swap(&a[begin],&a[i]);
			fun(a,begin+1,end);
			swap(&a[begin],&a[i]);
		}
	} 
}
int main(){
	char a[10]="XYZ";
	fun(a,0,strlen(a)-1);
	return 0;
} 
