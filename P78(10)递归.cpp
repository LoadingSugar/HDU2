#include<stdio.h> 
#include<math.h>
float sqrt(float A,float p,float e){
	if(fabs(p*p-A)<e)return p;
	else return sqrt(A,(p+A/p)/2,e);
}
float sqrt_A(float A,float p,float e){
	while((p*p-A)>=e)p=(p+A/p)/2;
	return p;
}
