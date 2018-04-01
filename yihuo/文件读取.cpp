#include<stdio.h> 
//#include<string.h>
int main(){
	FILE *fp=fopen("a.txt","rb");
	char buff[17]={'\0'};
	char ch;
	int pos=0;
	while(!feof(fp)){
		if(pos%16==0)printf("%.8x\t",pos);
		
		ch=fgetc(fp);
		printf("%.2x ",ch);
		if(ch>32&&ch<127)buff[pos%16]=(char)ch;else buff[pos%16]='.';
		pos++;
		if(pos%16==0)printf("\t%s\n",buff);
		
	}
	return 1;
}
