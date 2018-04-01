#include<stdio.h>
#include<string.h>
#include<windows.h>
void main()
{
	char s[20], *p, b[10], ch;
	int i=0, f=0, f1=1; 
	int x=0, c=0;
	int u=0;
	gets(s);
	p=s;    while(*++p!='\0');
	*p=' '; *(p+1)='\0';
	p=s;
	while(*p!='\0')
	{	
		if(*p>='0'&&*p<='9') { b[i++]=*p; f=1;}
		else if(f==1)
		{   
		if(*p>='a'&&*p<='z')  
			{ch=*p;
			if((u==0&&f1==0)||(u==1&&f1==1)){ b[i]='\0'; f=0; i=0; u=0; x=x+ atoi(b)*(-1);}
			else { b[i]='\0'; f=0; i=0;u=0; x+=atoi(b); }}
		else 
			if((u==0&&f1==0)||(u==1&&f1==1)){ b[i]='\0';  f=0; i=0; u=0; c+=atoi(b); }
			else { b[i]='\0'; f=0; i=0;u=0;  c=c+ atoi(b)*(-1);}
		}
		if(*p=='-')   u=1; 
		if(*p=='=')   f1=0; 
		p++;
	}
	printf("%c=%d",ch,c/x);
}
