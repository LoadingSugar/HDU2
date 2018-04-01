#include<stdio.h>
int main(){
	enum weekdayType {sun,mon,tue,wed,thu};
	enum weekdayType week;
	week=mon;
	printf("%d\n",week) ;
	enum weekdayType we[3]={mon,tue,wed};
	printf("%d\n",we[1]);//1 
	int *p;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	p=a+2;
	p=&a[2];
	*p=a[2];
	printf("%d\n",*p) ;//*p=3
	return 1;
} 
