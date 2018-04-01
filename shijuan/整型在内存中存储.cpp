#include<stdio.h> 

#include<string.h> 
unsigned char* i2ba(int n,unsigned char *s){
	s[0]=n%0XFF; 
	s[1]=(n>>8)%0XFF;
	s[2]=(n>>16)%0XFF;
	s[3]=(n>>24)%0XFF;
	return s; 
}
int main(){
	int x,i;
	scanf("%d",&x);
	
	return 0;
} 
