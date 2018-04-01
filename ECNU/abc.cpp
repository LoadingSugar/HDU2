#include<stdio.h>
using namespace std;
int main(){
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			for(int k=0;k<10;k++){
				int n1=i*100+j*10+k;
				int n2=j*100+k*10+k;
				if(n1+n2==532)
				printf("%d %d %d\n",i,j,k);
			} 
		}
	}
	return 0;
} 
