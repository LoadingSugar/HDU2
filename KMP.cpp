#include<stdio.h> 
#include<stdlib.h>
#include<string>
#define maxSize 15
typedef struct {
	char *str;
	int length;
}Str;
int naive(Str str,Str substr) {
	int i=1,j=1,k=1;
	while(i<=str.length&&j<=substr.length){
		if(str.str[i]==substr.str[j]){
			i++;
			j++;
		}else{
			j=1;
			i=++k;//i=k++会出问题 
		}
	} 
	if(j>substr.length)return k;
	else return 0;
}
int KMP(Str str,Str substr,int next[]){
	int i=1,j=1;
	while(i<=str.length&&j<=substr.length){
		if(j==0||str.str[i]==substr.str[j]){
			j++;
			i++;
		}else{
			j=next[j];
		}
	}
	if(j>substr.length)return i-substr.length;
	else return 0;
}
void getnext(Str substr,int next[]){
	next[1]=0;
	int j=1,t=0;//过程中t可能被赋值为0，应此在这边赋值为0 
	while(j<substr.length){//注意是小于号 
		if(t==0||substr.str[j]==substr.str[t]){//t为0，表示重合串长度为0，next[]值为0+1 
			next[j+1]=t+1;
			j++;
			t++; 
		}else{
			t=next[t];
		}
	}
}
//改进后的next[]数组 
void getNextval(Str substr,int nextval[],int next[]) {
	nextval[1]=0,next[1]=0;
	int j=1,t=0;
	while(j<substr.length){
		if(t==0||substr.str[j]==substr.str[t]){
			next[j+1]=t+1;
			if(substr.str[j+1]==substr.str[next[j+1]]) {
				nextval[j+1]=nextval[next[j+1]];
			}else{
				nextval[j+1]=next[j+1];
			}
			j++;
			t++;
		}
		else{
			t=next[t];
		}
	}
}
void getNextval2(Str substr,int nextval[]) {
	nextval[1]=0;
	int j=1,t=0;
	while(j<substr.length){
		if(t==0||substr.str[j]==substr.str[t]){
			if(substr.str[j+1]==substr.str[t+1]) {
				nextval[j+1]=nextval[t+1];
			}else{
				nextval[j+1]=t+1;
			}
			j++;
			t++;
		}
		else{
			t=nextval[t];
		}
	}
}
int main(){
	char c[18]="ABABBBAAABABABBA",a[8]="ABABABB";
	Str str,substr;
	str.length=16,substr.length=7;
	str.str=(char*)malloc((str.length+1)*sizeof(char));
	substr.str=(char *)malloc(sizeof(char)*(substr.length+1));
	puts("-------------------------");
	int i=0;
	while(c[i]!='\0')
		str.str[i+1]=c[i++];
	i=0;
	while(a[i]!='\0')
		substr.str[i+1]=a[i++];
	int next[8];
	getnext(substr,next);
	//输出next  0 1 1 2 3 4 5
	for(int i=1;i<8;i++){
		printf("%d\t",next[i]);
	}
	printf("\n");
	//输出substr 
	for(int i=1;i<=substr.length;i++)printf("%c",substr.str[i]);
	printf("\n");
	int p=KMP(str,substr,next);
	printf("%d",p);
	p=naive(str,substr);
	printf("\n%d",p);
	int nextval[8];
	getNextval2(substr,nextval);
	p=KMP(str,substr,nextval);
	printf("\n%d",p);
	return 1;
}
