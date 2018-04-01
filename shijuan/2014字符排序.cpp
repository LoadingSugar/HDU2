#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct {
	char s[10000];
	int hashnum;
}str; 
int comp(const void *a,const void *b){
	str *aa=(str *)a;str *bb=(str *)b;
	int ha=aa->hashnum-bb->hashnum;
	if(ha>0)return 1;
	if(ha==0){
		int diff=strlen(bb->s)-strlen(aa->s);//由大到小 
		return diff?diff:strcmp(bb->s,aa->s);//由大到小
	}
}
int hash(char *s){
	int sum;
	for(int i=0;i<strlen(s);i++){
		sum+=(sum+s[i])%1007;
	} 
	return sum;
} 
int main(){
	FILE *in,*out; 
	if((in=fopen("d:\\data.in","r"))==NULL){
		printf("open failure");return 0;
	}
	if((out=fopen("d:\\data.out","w"))==NULL){
		printf("open failure");return 0;
	}
	str st[MaxSize];
	int n=10,i=0;
	while(!feof(in)&&i<n){
	//	fsanf(in,"%s",st[i].s);有问题遇到空格会停止
	fgets(st[i].s,10000,in);
	st[i].hashnum=hash(st[i].s);
	++i; 
	}
	qsort(st,n,sizeof(str),comp);
	for(int j=0;j<n;j++)
		fputs(st[j].s,out);
	fclose(in);
	fclose(out);
	return 0;
} 
