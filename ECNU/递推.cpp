#include <stdio.h>
#define N 20000
//假设k<20000
int main()
{
    int a[N];
    int p, q, k;
    while(scanf("%d %d %d %d %d",&a[0], &a[1], &p ,&q, &k)!=EOF)
    {
        for(int i=2; i<k+1; i++)//不用算太多，把a[k]算出来就完事
        {
            a[i]=(p*a[i-1]+q*a[i-2])%10000;//每个数顺手就取模了，防止溢出
        }
        printf("%d\n", a[k]);
    }
    return 0;//大功告成
}
