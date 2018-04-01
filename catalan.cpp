#include<stdio.h> 
//f(n)=f(0)*f(n-1)+f(1)*f(n-2)+f(2)*f(n-3)...+f(n-1)*f(0)
int catalan(int x){
	if(x<2)return 1;
	else return catalan(x-1)*(4*x-2)/(x+1);
}
long catalan2(int x){
	if(x<2)return 1;
	long *h=new long[x+1];
	h[0]=h[1]=1;
	for(int i=2;i<=x;i++){
		h[i]=0;
		for(int j=0;j<i;j++)
			h[i]+=h[j]*h[i-1-j];
	}
	long result=h[x];
	delete[] h;
	return result;
} 
int main(){
	for(int i=0;i<10;i++)
		printf("%d\n",catalan2(i));
}
