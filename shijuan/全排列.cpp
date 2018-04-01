#include<iostream>

using namespace std;


//index，代表递归过程中，子数列在原始数列中的位置	
//例如 a[] = {1,2,3},原始数列长度LENGTH = 3，
//递归到其中某一步时index = 1，num= 2，代表要从原始数列的下表为1处，长度为2(即自数列2，3)开始，查找子数列
//(2,3)的全排列

//LENGTH 为原始数组的长度，这个是不会变的。
void permutation(int values[], int index, int num,int LENGTH)
{
 int i = 0;
 if(num == 0)//已经找到一个全排列，显示输出
 {
  for(i=0; i<LENGTH;++i)
  {
   cout<<values[i]<<" ";
  }
  cout<<endl;

  return;
 }
 for(i=0; i<num; i++)
 {
  swap(values[index+i], values[index]);//第index个整数和第index+i个数字交换，保证自数列的第一个元素与该子数列中每一个元素进行一次交换，进行排列。

  
  permutation(values, index+1, num-1,LENGTH);//对从index+1到数组最末端的元素进行全排列

  
  //swap(values[index+i], values[index]);//for循环中第一条语句的逆操作，其目的是使数组倒回原来的样子，
  //这样做的目的是使排列不会产生重复的结果。
 }

 return;
}

int main()
{
 int values[]={1,3,5};
 
 permutation(values,0,3,3);

 cout<<endl<<endl;
 cout<<endl<<endl;
 
 return 0;
}
