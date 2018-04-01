#include <stdio.h> 
#include <string.h>
int main(){
	char str[4];
	while(scanf("%s",str)!=EOF){
		int i;
		int num=strlen(str);
		for(i=num-1;i>=0;i--)
			printf("%c",str[i]);
		printf("\n");
	}
	return 0; 
}
