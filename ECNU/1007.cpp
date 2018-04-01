#include<stdio.h>

int main()
{
    double fact,n,i;
    while(scanf("%lf",&n)!=EOF){
    fact=1;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
        while(fact>=10)
            fact=fact/10;
    }
    printf("%.0f\n",fact);
	}
    return 0;
}

