/*
*�㷨˼�룺�򵥵�˵�����ǵ�һ�����ֱ��Ժ���������н���
*E��g��E = ��a , b , c������ prem��a,b,c��= a.perm��b,c��+ b.perm��a,c��+ c.perm��a,b��
*Ȼ��a.perm��b,c��= ab.perm��c��+ ac.perm��b��= abc + acb.���εݹ���С�
*ȥ���ظ����ŵ�ȫ���У��ڽ���֮ǰ�������ж����������Ƿ���ͬ������ͬ�Ž�����
*���ʱ����Ҫһ���жϷ����Ƿ���ͬ�ĺ�����
*/
// abb,��һ������ڶ��������������ԣ����ڵ���������ڶ�������ͬ�����������н�����һ����������b��ͬ��һ�ֽ����ظ�------ֻ����ǰ���裩 
//˼·:���ν���ͬԪ�ط��ڵ�һ���������Ԫ���Լ���ȫ���м�f(n-1) 
#include <iostream>
#include <algorithm>
using namespace std;
int cnt = 1;    //��¼���еĸ���

bool isSwap(int p[],int nBegin, int nEnd)
{
    for(int j = nBegin; j < nEnd; j++)
    {
        if(p[j] == p[nEnd])
            return false;
    }
    return true;
}

//start ��ʾ��ǰ����,n��ʾ���������ĸ���
void   permutation(int p[],int cur,int n)
{
    if(cur == n-1)
    {
         cout<<"?"<<cnt++<<"????: ";
         for(int i = 0; i < n; i++)
             cout<<p[i];
        cout<<"���"<<endl;
    }
    else
    {
        for(int i = cur; i <= n-1; i ++)       //��i�����ֱ�������������ֽ������ܵõ��µ�����
        {
            if(isSwap(p,cur,i))                  //�ж��Ƿ����,�м�����ȵ�Ԫ�����轻��
            {
            	printf("���ظ�cur=%d i=%d\n%d %d %d\n",cur,i,p[0],p[1],p[2]);
            	
                swap(p[cur],p[i]);
                permutation(p,cur+1,n);
                swap(p[cur],p[i]);
            }
            else{
            	
				printf("���ظ�cur=%d i=%d\n%d %d %d\n",cur,i,p[0],p[1],p[2]);
			}
            	
        }
    }
}

int main()
{
    int p[] = {1,2,2};
    permutation(p,0,3);

    return 0;
}
