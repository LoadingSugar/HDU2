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
   if(!(dfp=fopen("D:\\Code\\yan\\file\\test\\dfile.txt","a"))) //���ӵķ�ʽд       
    {
     printf("Destination file cannot be opened\n");return 0;
    }
    char re[10]="helloDear",ra[10]="";
    fprintf(dfp,"%s\n",re);//reд�뵽dfp�� 
    while(!feof(sfp))//�ж��ǲ����ļ�β 
		fscanf(sfp,"%s",re);//sfp�ļ�д��re��     ÿ���Կո�ֹͣ 
    fseek(sfp,0L,0);//�����ļ�ָ��ָ���ļ���һ����ʼλ��
							//fseek(fp,100L,0);     // ��λ��ָ���ƶ������ļ���ͷ100�ֽڴ�
							//fseek(fp,100L,1);     // ��λ��ָ���ƶ������ļ���ǰλ��100�ֽڴ�
							//fseek(fp,-100L,2);    // ��λ��ָ���˻ص����ļ���β100�ֽڴ� 
    fgets(ra,4,sfp);//��sfp�ļ�������ȡbufsize-1���ַ�����bufsize���ַ���'\0'��
	fputs(ra,dfp); 
    printf("%s",ra);
    fclose(sfp);
    fclose(dfp);
}
