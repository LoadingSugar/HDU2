#include<stdio.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	char str[33];
	int tmp[4];
	while(n){
		scanf("%s",str);
		int t,num;
		for(int i=31,j=-1;i>=0;i--) {
			if(i%8==7){
				t=1;num=0;
				j++;
			}
			num+=(str[i]-'0')*t;
			t*=2;
			if(i%8==0){
				tmp[j]=num; 
			} 
		}
		for(int i=3;i>=0;i--){
			printf("%d",tmp[i]);
			if(i>0)printf(".");
			if(i==0)printf("\n");
		}
		n--;
	}
	return 0;
}
