#include<stdio.h>

#define BUFFSIZE 5000
int main()
{
FILE * sfp,* dfp;
int i;
char buf[BUFFSIZE];
if((sfp=fopen("D:\\Code\\yan\\file\\test\\sfile.txt","r"))==NULL)        /*以只读方式打开*/
{
   printf("Source file cannot be opened\n");
   return 0;
   }
   if(!(dfp=fopen("D:\\Code\\yan\\file\\test\\dfile.txt","w")))                /*以只写方式打开*/
    {
     printf("Destination file cannot be opened\n");
     return 0;
     }
     i=0;
     while(!feof(sfp))                        /*判断是否文件尾，不是则循环*/
     {
      buf[i++]=fgetc(sfp);                 /*读出数据送缓冲区*/
      if(i>=5000)                              /*若i超出5000，程序设置的缓冲区不足*/
       {
        printf("buffer not enough!");
        return 0;
        }
      }
      printf("%d\n",i);
      for(int j=0;j<i;j++)printf("%c",buf[j]);
      while(--i>=0)                         /*控制反序操作*/
      fputc(buf[i],dfp); 
	                     /*写入目的文件中*/
      fclose(sfp);
      fclose(dfp);
}
