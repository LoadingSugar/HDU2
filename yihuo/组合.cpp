#include <iostream>
using namespace std;
void Combine(int a[], int n ,int m, int b[], const int M);

int main()
{
     //��N������ѡM������N=6��M=3
     const int N = 6;
     const int M = 3;

     int a[N];
     int b[M]; //�����洢��ǰ�����Ԫ��(����洢��Ԫ���±�)
     for (int i = 0; i < N; i++)
         a[i] = i+1;

     Combine(a, N, M, b, M);

     return 0;
}

void Combine(int a[], int n ,int m,int k,int j)
{
     for (int i = n; i >= m; i--)
     {
         b[m-1] = i -1; //ѡȡ��ѡ��a[]������һ��������¼���±�
         if (m > 1)
             Combine(a, i-1, m-1, b, M); //��n-1����ѡm-1��Ԫ��
         else //1==m��û��Ԫ�ؿ�ѡ��һ������Ѿ���ɣ����
     {
     for (int j = M-1; j >= 0; j--)
          cout<<a[b[j]];
     cout<<endl;
      }
    }
}
