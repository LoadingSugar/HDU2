/*
*算法思想：简单地说：就是第一个数分别以后面的数进行交换
*E．g：E = （a , b , c），则 prem（a,b,c）= a.perm（b,c）+ b.perm（a,c）+ c.perm（a,b）
*然后a.perm（b,c）= ab.perm（c）+ ac.perm（b）= abc + acb.依次递归进行。
*去掉重复符号的全排列：在交换之前可以先判断两个符号是否相同，不相同才交换，
*这个时候需要一个判断符号是否相同的函数。
*/
// abb,第一个数与第二个数交换，可以，由于第三个数与第二个数相同，（若还进行交换第一个数还等于b，同第一种交换重复------只看当前步骤） 
//思路:依次将不同元素放在第一个，后面的元素自己求全排列即f(n-1) 
#include <iostream>
#include <algorithm>
using namespace std;
int cnt = 1;    //记录排列的个数

bool isSwap(int p[],int nBegin, int nEnd)
{
    for(int j = nBegin; j < nEnd; j++)
    {
        if(p[j] == p[nEnd])
            return false;
    }
    return true;
}

//start 表示当前的数,n表示数组中数的个数
void   permutation(int p[],int cur,int n)
{
    if(cur == n-1)
    {
         cout<<"?"<<cnt++<<"????: ";
         for(int i = 0; i < n; i++)
             cout<<p[i];
        cout<<"输出"<<endl;
    }
    else
    {
        for(int i = cur; i <= n-1; i ++)       //第i个数分别与它后面的数字交换就能得到新的排列
        {
            if(isSwap(p,cur,i))                  //判断是否相等,中间是相等的元素则不需交换
            {
            	printf("无重复cur=%d i=%d\n%d %d %d\n",cur,i,p[0],p[1],p[2]);
            	
                swap(p[cur],p[i]);
                permutation(p,cur+1,n);
                swap(p[cur],p[i]);
            }
            else{
            	
				printf("有重复cur=%d i=%d\n%d %d %d\n",cur,i,p[0],p[1],p[2]);
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
