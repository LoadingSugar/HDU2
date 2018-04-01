#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    vector<string> v, vs;
    vector< vector<string> > ve;
    while(cin>>n)
    {
        string str;
        if(n==0) return 0;
 
        v.clear();  //��ų�ʼ��������
        for(int i = 0; i<n; i++)
        {
            cin>>str;
            while(str[str.length()-1]!='\\') str+='\\';  //��ÿ�н��д�������������\��ĸ��·����ʽ
            v.push_back(str);
        }
        sort(v.begin(), v.end());  //����
 
        ve.clear();  //��ά�����ʼ��
        for(int i = 0; i<v.size(); i++)
        {
            int begin = 0, end = 0;
            vs.clear();  //ÿ��һά�����ʼ��
            while((end = v[i].find("\\", begin))!=string::npos){
                vs.push_back(v[i].substr(begin, end-begin));
                begin=end+1;
            }
            ve.push_back(vs);  //��Ž���ά������
        }
        for(int i = 0; i<n; i++)
        {
            if(i>0 && ve[i][0] == ve[i-1][0])  //��ǰһ��Ŀ¼����ͬ�ĸ�Ŀ¼
            {
                int j = 1;
                while(j<ve[i].size() && ve[i][j]==ve[i-1][j]) j++;  //�ҵ���һ����ͬ��Ŀ¼
                for(; j<ve[i].size(); j++)
                {
                    for(int k = 0; k<j; k++)
                        cout<<"  ";  //j�Ǹ�Ŀ¼�ڸ�·���е��±꣬���������Ĵ���
                    cout<<ve[i][j]<<endl;
                }
            }
            else{
                for(int j = 0; j<ve[i].size(); j++)
                {
                    for(int k = 0; k<j; k++)
                        cout<<"  ";
                    cout<<ve[i][j]<<endl;
                }
            }
        }
        cout<<endl;  //ÿ���������������һ������
    }
    return 0;
}
