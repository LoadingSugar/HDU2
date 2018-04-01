#include<stdio.h> 
#include<stdlib.h>
#define maxSize 50
typedef struct {
	int x;
}SNode;
SNode nod[12];

int main(){
	nod[1].x=10;
	printf("%d",nod[1].x);
	return 0;
} 
