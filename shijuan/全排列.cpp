#include<iostream>

using namespace std;


//index������ݹ�����У���������ԭʼ�����е�λ��	
//���� a[] = {1,2,3},ԭʼ���г���LENGTH = 3��
//�ݹ鵽����ĳһ��ʱindex = 1��num= 2������Ҫ��ԭʼ���е��±�Ϊ1��������Ϊ2(��������2��3)��ʼ������������
//(2,3)��ȫ����

//LENGTH Ϊԭʼ����ĳ��ȣ�����ǲ����ġ�
void permutation(int values[], int index, int num,int LENGTH)
{
 int i = 0;
 if(num == 0)//�Ѿ��ҵ�һ��ȫ���У���ʾ���
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
  swap(values[index+i], values[index]);//��index�������͵�index+i�����ֽ�������֤�����еĵ�һ��Ԫ�������������ÿһ��Ԫ�ؽ���һ�ν������������С�

  
  permutation(values, index+1, num-1,LENGTH);//�Դ�index+1��������ĩ�˵�Ԫ�ؽ���ȫ����

  
  //swap(values[index+i], values[index]);//forѭ���е�һ���������������Ŀ����ʹ���鵹��ԭ�������ӣ�
  //��������Ŀ����ʹ���в�������ظ��Ľ����
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
