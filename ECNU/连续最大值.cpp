#include <stdio.h>
#include<algorithm>
#define N 20000
using namespace std;
int main()
{
    int a;
    int p[10001];
    while(scanf("%d",&a)!=EOF)
    {	
    	int sum=0,ma=-999999;
        for(int i=0; i<a; i++)//������̫�࣬��a[k]�����������
        {
        	int x;
        	scanf("%d",&x);
            sum=max(sum+x,x);
            ma=max(ma,sum);
        }
        printf("%d\n",ma);
    }
    return 0;//�󹦸��
}
