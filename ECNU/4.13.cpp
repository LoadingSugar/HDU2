#include<stdio.h> 
#include<stack>
#include<iostream>
using namespace std;
#define max 100
struct big{
	int digit[max];
	int size;
	void init(){
		for(int i=0;i<max;i++)digit[i]=0;
		size=0;
	}
	void set(int x){
		init();
		do{
			digit[size++]=x%10000;
			x/=10000;
		}while(x!=0);
	}
	
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i!=size-1)printf("%04d",digit[i]);
			else printf("%4d",digit[i]);
		}
	} 
	big operator *(int x) const{
		big ret;
		ret.init();
		int carry=0;
		for(int i=0;i<size;i++){
			int temp=digit[i]*x;
			carry=temp%10000;
			ret.digit[ret.size++]=temp/10000;
		}
		if(carry)ret.digit[ret.size++]=carry;
		return carry;
	}
	big operator +(const big &A) const{
		big ret;
		ret.init();
		int carry=0;
		for(int i=0;i<A.size||i<size;i++){
			int temp=A.digit[i]+digit[i]+carry;
			carry=temp%10000;
			ret.digit[ret.size++]=temp/10000;
		}
		if(carry)ret.digit[ret.size++]=carry;
		return ret;
	}
	big operator /(inr x){
		big ret;
		ret.init();
		int carry=0;
		for(int i=size-1;i>=0;i--){
			int t=(carry*10000+digit[i])/10000;
			int r=(carry*10000+digit[i])%10000;
			ret.digit[i]=t;
			carry=r;
		}
		ret.size=0;
		for(int i=0;i<=max;i++){
			if(digit[i]!=0)ret.size=i;
		}
		ret.size++;
		return ret;
	} 
	big operator % (int x){
		int carry;
		for(int i=size-1;i>=0;i--){
			int t=(carry*10000+digit[i])/x;
			int r=(carry*10000+digit[i])%x;
			carry=r;
		}	
		return carry;
	}
}a,b,c;
char str[1000];
char ans[1000];
int main(){
	char m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		cin>>str;
		int L=strlen(str);
		
	}
	return 0;
}
