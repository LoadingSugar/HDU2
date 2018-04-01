#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int   len =120; 
char infix[len],suffix[len];
void infixtosuffix()//将前缀表达式转换成后缀表达式 
{
	int top=-1,i=0,j=0;
	char ch=infix[0],stk[len];
	while(ch!='\0')
	{
		if(ch==' ')
		{}
		else if(ch=='(')
		{
			top++;stk[top]=ch;
		}
		else if(ch==')')
		{
			while(stk[top]!='(')
			{
				suffix[j++]=stk[top];top--;
			}
			top--;
		}
		else if(ch=='!'||ch=='！')
		{
			top++;stk[top]=ch;
		}
		else if(ch=='&'||ch=='&')
		{
			while(stk[top]=='&'||stk[top]=='!')
			{
				suffix[j++]=stk[top];top--;
			}
			top++;stk[top]=ch;
		}
		else if(ch=='|'||ch=='！')
		{
			while(top!=-1&&stk[top]!='(')
			{
				suffix[j++]=stk[top];top--;
			}
			top++;stk[top]=ch;
		}
		else
		{
			suffix[j++]=ch;
			while(top!=-1&&stk[top]=='!')
			{
				suffix[j++]=stk[top];top--;
			}
		}
		ch=infix[++i];
	}
	while(top!=-1)
	{
		suffix[j++]=stk[top];top--;
	}
	suffix[j++]='\0';
}
void pri_result()//对后缀数组进行计算 
{
	int i=0,top=-1;
	char ch=suffix[i];
	bool result[len];
	while(ch!='\0')
	{
		if(ch=='F'||ch=='f')
		{
			top++;result[top]=false;
		}
		else if(ch=='V'||ch=='v')
		{
			top++;result[top]=true;
		}
		else if(ch=='!'||ch=='！')
			result[top]=!result[top];
		else if(ch=='|')
		{
			result[top-1]|=result[top];
			top--;
		}
		else if(ch=='&')
		{
			result[top-1]&=result[top];
			top--;
		}
		ch=suffix[++i];
	}
	if(result[top]==true)
		printf("V\n");
	else printf("F\n");
}
int main()
{
	int i=1;
	while(cin.getline(infix,len))
	{
		infixtosuffix();
		printf("Expression %d: ",i++);
		pri_result();
	}
	return 0;
}
