#include <iostream>
using namespace std;
void Combine(int a[], int n ,int m, int b[], const int M);

int main()
{
     //从N个数中选M个数，N=6，M=3
     const int N = 6;
     const int M = 3;

     int a[N];
     int b[M]; //用来存储当前组合中元素(这里存储是元素下标)
     for (int i = 0; i < N; i++)
         a[i] = i+1;

     Combine(a, N, M, b, M);

     return 0;
}

void Combine(int a[], int n ,int m,int k,int j)
{
     for (int i = n; i >= m; i--)
     {
         b[m-1] = i -1; //选取候选集a[]中最大的一个数，记录其下标
         if (m > 1)
             Combine(a, i-1, m-1, b, M); //从n-1中再选m-1个元素
         else //1==m，没有元素可选，一个组合已经完成，输出
     {
     for (int j = M-1; j >= 0; j--)
          cout<<a[b[j]];
     cout<<endl;
      }
    }
}
