#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<string>
#define maxSize 50
#define MIN 0.001
int getPriority(char op){
	if(op=='-'||op=='+')return 0;
	else return 1;
}
int calSub(float opand1,char op,float opand2,float &result){
	if(op=='-')result=opand1-opand2;
	if(op=='+')result=opand1+opand2;
	if(op=='*')result=opand1*opand2;
	if(op=='/'){
		if(fabs(opand2)<MIN)return 0;
		else result=opand1/opand2;
	} 
	return 1;
}
int calStackTopTwo(float st2[],int &top2,char st1[],int &top1){
	float opand2=st2[top2--],opand1=st2[top2--];
	char op=st1[top1--];
	float result;
	int flag=calSub(opand1,op,opand2,result);
	if(!flag){
		puts("ERROR");
	}
	st2[++top2]=result;
	return flag;
}
float claInfix(char exp[]){
	int i=0,top1=-1,top2=-1;
	char st1[maxSize];
	float st2[maxSize];
	while(exp[i]!='\0'){
		if('0'<=exp[i]&&exp[i]<='9')st2[++top2]=exp[i++]-'0';
		else if(exp[i]=='(')st1[++top1]=exp[i++];
			else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'){
				if(top1==-1||st1[top1]=='('||
				getPriority(st1[top1])<getPriority(exp[i])){
					st1[++top1]=exp[i++]; 
				}else{
					int flag=calStackTopTwo(st2,top2,st1,top1);
					if(!flag)return 0;
				}
			}
			else if(exp[i]==')'){
				while(st1[top1]!='('){
					int flag=calStackTopTwo(st2,top2,st1,top1);
					if(!flag)return 0;
				}
				top1--;
				i++;
			}
		
	}
		//特别容易忘记
	while(top1!=-1) {
			int flag=calStackTopTwo(st2,top2,st1,top1);
			if(flag==0)return 0;
	}
	return st2[top2];
}
int main(){
	char exp[]="1*2-1-(1*3)/6";
	printf("%f\n",claInfix(exp));
}
