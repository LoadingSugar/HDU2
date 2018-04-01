#include<stdio.h>
int get5(int n)
	{return n==0?0:(n/5+get5(n/5));}
int get2(int n){
	return n==0?0:(n/2+get2(n/2));
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
    	int tmp;
    	scanf("%d",&tmp);
   		int t=get5(tmp);
   		printf("%d\n",t);
	}
    return 0;
}

