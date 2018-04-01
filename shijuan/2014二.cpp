#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TIMES 6000000
struct T{int key,value;};
int main(){
	int i;
	struct T a[12];
	for(i=0;i<12;i++){
		a[i].key=i+1;
		a[i].value=0;
	}
	srand((unsigned)time(0));
	for(i=0;i<TIMES;i++){
		int v=(rand()%6+1)+(rand()%6+1);
		a[v-1].value++;
	}
	for(i=0;i<12;i++)printf("%2d: %.2f\n",a[i].key,(double)a[i].value/TIMES);
	return 0;
}
