#include <stdio.h>
#define N 20000
//����k<20000
int main()
{
    int a[N];
    int p, q, k;
    while(scanf("%d %d %d %d %d",&a[0], &a[1], &p ,&q, &k)!=EOF)
    {
        for(int i=2; i<k+1; i++)//������̫�࣬��a[k]�����������
        {
            a[i]=(p*a[i-1]+q*a[i-2])%10000;//ÿ����˳�־�ȡģ�ˣ���ֹ���
        }
        printf("%d\n", a[k]);
    }
    return 0;//�󹦸��
}
