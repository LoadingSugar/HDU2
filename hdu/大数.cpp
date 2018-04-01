#include <stdio.h>
#include <string.h>
#include<algorithm>
struct bigInteger   //高精度整数结构体
{
    int digit[1000]; //按四位数一个单位保存数值
    int size; //下一个我们未使用的数组单元
    void init()   //对结构体的初始化
    {
        for (int i = 0; i < 1000; i ++)
            digit[i] = 0; //所有数位清0
        size = 0; //下一个未使用数组单元为0,即没有一个单元被使用
    }
    void set(char str[])   //从字符串中提取整数
    {
        init(); //对结构体初始化
        int L = strlen(str); //计算字符串长度
        for (int i = L - 1,j = 0,t = 0,c = 1; i >= 0; i --)
        {
            t += (str[i] - '0') * c; //计算这个四位数中当前字符代表的数字,即数字乘以当前位权重
            j ++; //当前转换字符数增加
            c *= 10; //计算下一位权重
            if (j == 4 || i == 0)   //若已经连续转换四个字符,或者已经到达最后一个字符
            {
                digit[size ++] = t; //将这四个字符代表的四位数存入数组,size移动到下一个数组单位
                j = 0;//重新开始计算下4个字符
                t = 0;//临时变量清0
                c = 1; //权重变为1
            }
        }
    }
    void output()   //将该高精度整数输出
    {
        for (int i = size - 1; i >= 0; i --)
        {
            if (i != size - 1)
                printf("%04d",digit[i]); //若当前输出的数字不是最高位数字,用%04的输出前导0,即当前数字不足4位时由0补充,如输出110001的后四位数
            else
                printf("%d",digit[i]); //若是最高位,则无需输出前导零
        }
        printf("\n"); //换行
    }
    bigInteger operator + (const bigInteger &A) const   //加法运算符
    {
        bigInteger ret; //返回值,即两数相加的结果

        ret.init();

//对其初始化

        int carry = 0; //进位,初试值为0
        for (int i = 0; i < A.size || i < size; i ++)
        {
            int tmp = A.digit[i] + digit[i] + carry; //计算两个整数当前位以及来自低位的进位和
            carry = tmp / 10000; //计算该位的进位
            tmp %= 10000; //去除进位部分,取后四位
            ret.digit[ret.size ++] = tmp; //保存该位结果
        }
        if (carry != 0)   //计算结束后若最高位有进位
        {
            ret.digit[ret.size ++] = carry; //保存该进位
        }
        return ret; //返回
    }
} a, b, c;
char str1[1002], str2[1002];
int main ()
{
    while (scanf ("%s%s",str1,str2) != EOF)   //输入
    {
        a.set(str1);
        b.set(str2); //用两个字符串分别设置两个高精度整数
        c = a + b; //计算它们的和
        c.output(); //输出
    }
    return 0;
}
