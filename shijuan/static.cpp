#include<stdio.h> 
//auto int i=10;
int  fun(){
	static int i=1;
	i++;
	
	return i;
	//printf("hello%d\n",i);
	//return i;
}
int main(){
	//auto int i=0;
	fun();
	printf("%d\n",fun());
	fun();
	printf("%d\n",fun());
} 
