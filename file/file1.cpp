#include<stdio.h>
#define BUFFSIZE 5000
int main()
{
	FILE * sfp,* dfp;
	int i;
	char buf[BUFFSIZE];
	if((sfp=fopen("D:\\Code\\yan\\file\\test\\sfile.txt","r"))==NULL)        
	{
   		printf("Source file cannot be opened\n");return 0;
    }
   if(!(dfp=fopen("D:\\Code\\yan\\file\\test\\dfile.txt","a"))) //附加的方式写       
    {
     printf("Destination file cannot be opened\n");return 0;
    }
    char re[10]="helloDear",ra[10]="";
    fprintf(dfp,"%s\n",re);//re写入到dfp中 
    while(!feof(sfp))//判断是不是文件尾 
		fscanf(sfp,"%s",re);//sfp文件写到re中     每次以空格停止 
    fseek(sfp,0L,0);//调整文件指针指向文件第一个起始位置
							//fseek(fp,100L,0);     // 把位置指针移动到离文件开头100字节处
							//fseek(fp,100L,1);     // 把位置指针移动到离文件当前位置100字节处
							//fseek(fp,-100L,2);    // 把位置指针退回到离文件结尾100字节处 
    fgets(ra,4,sfp);//从sfp文件中最多读取bufsize-1个字符（第bufsize个字符赋'\0'）
	fputs(ra,dfp); 
    printf("%s",ra);
    fclose(sfp);
    fclose(dfp);
}
