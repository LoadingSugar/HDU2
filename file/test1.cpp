#include<stdio.h>

#define BUFFSIZE 5000
int main()
{
FILE * sfp,* dfp;
int i;
char buf[BUFFSIZE];
if((sfp=fopen("D:\\Code\\yan\\file\\test\\sfile.txt","r"))==NULL)        /*��ֻ����ʽ��*/
{
   printf("Source file cannot be opened\n");
   return 0;
   }
   if(!(dfp=fopen("D:\\Code\\yan\\file\\test\\dfile.txt","w")))                /*��ֻд��ʽ��*/
    {
     printf("Destination file cannot be opened\n");
     return 0;
     }
     i=0;
     while(!feof(sfp))                        /*�ж��Ƿ��ļ�β��������ѭ��*/
     {
      buf[i++]=fgetc(sfp);                 /*���������ͻ�����*/
      if(i>=5000)                              /*��i����5000���������õĻ���������*/
       {
        printf("buffer not enough!");
        return 0;
        }
      }
      printf("%d\n",i);
      for(int j=0;j<i;j++)printf("%c",buf[j]);
      while(--i>=0)                         /*���Ʒ������*/
      fputc(buf[i],dfp); 
	                     /*д��Ŀ���ļ���*/
      fclose(sfp);
      fclose(dfp);
}
