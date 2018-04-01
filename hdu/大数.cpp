#include <stdio.h>
#include <string.h>
#include<algorithm>
struct bigInteger   //�߾��������ṹ��
{
    int digit[1000]; //����λ��һ����λ������ֵ
    int size; //��һ������δʹ�õ����鵥Ԫ
    void init()   //�Խṹ��ĳ�ʼ��
    {
        for (int i = 0; i < 1000; i ++)
            digit[i] = 0; //������λ��0
        size = 0; //��һ��δʹ�����鵥ԪΪ0,��û��һ����Ԫ��ʹ��
    }
    void set(char str[])   //���ַ�������ȡ����
    {
        init(); //�Խṹ���ʼ��
        int L = strlen(str); //�����ַ�������
        for (int i = L - 1,j = 0,t = 0,c = 1; i >= 0; i --)
        {
            t += (str[i] - '0') * c; //���������λ���е�ǰ�ַ����������,�����ֳ��Ե�ǰλȨ��
            j ++; //��ǰת���ַ�������
            c *= 10; //������һλȨ��
            if (j == 4 || i == 0)   //���Ѿ�����ת���ĸ��ַ�,�����Ѿ��������һ���ַ�
            {
                digit[size ++] = t; //�����ĸ��ַ��������λ����������,size�ƶ�����һ�����鵥λ
                j = 0;//���¿�ʼ������4���ַ�
                t = 0;//��ʱ������0
                c = 1; //Ȩ�ر�Ϊ1
            }
        }
    }
    void output()   //���ø߾����������
    {
        for (int i = size - 1; i >= 0; i --)
        {
            if (i != size - 1)
                printf("%04d",digit[i]); //����ǰ��������ֲ������λ����,��%04�����ǰ��0,����ǰ���ֲ���4λʱ��0����,�����110001�ĺ���λ��
            else
                printf("%d",digit[i]); //�������λ,���������ǰ����
        }
        printf("\n"); //����
    }
    bigInteger operator + (const bigInteger &A) const   //�ӷ������
    {
        bigInteger ret; //����ֵ,��������ӵĽ��

        ret.init();

//�����ʼ��

        int carry = 0; //��λ,����ֵΪ0
        for (int i = 0; i < A.size || i < size; i ++)
        {
            int tmp = A.digit[i] + digit[i] + carry; //��������������ǰλ�Լ����Ե�λ�Ľ�λ��
            carry = tmp / 10000; //�����λ�Ľ�λ
            tmp %= 10000; //ȥ����λ����,ȡ����λ
            ret.digit[ret.size ++] = tmp; //�����λ���
        }
        if (carry != 0)   //��������������λ�н�λ
        {
            ret.digit[ret.size ++] = carry; //����ý�λ
        }
        return ret; //����
    }
} a, b, c;
char str1[1002], str2[1002];
int main ()
{
    while (scanf ("%s%s",str1,str2) != EOF)   //����
    {
        a.set(str1);
        b.set(str2); //�������ַ����ֱ����������߾�������
        c = a + b; //�������ǵĺ�
        c.output(); //���
    }
    return 0;
}
