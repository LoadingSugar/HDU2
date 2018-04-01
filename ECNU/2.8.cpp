#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<iostream> 
using namespace std;
bool flag=true;
int main(){
	int x,y;
	int n;
	char a,b;
	char buf[80][80];
	while(scanf("%d %c %c",&n,&a,&b)==3){
		if(flag==true)flag=false;
		else cout<<endl;
		x=n/2+1,y=n/2+1;
		for(int i=1,j=1;i<=n;i+=2,j++){
			char c=j%2==1?a:b;
			for(int k=1;k<=n;k++){
				buf[x][y+k-2]=c;
				buf[x+i-1][y+k-2]=c;
				buf[x+k-1][y]=c;
				buf[x+k-1][y+i-1]=c;
			}
			x--,y--;
		}
		if(n!=1){
			buf[1][1]=' ';
			buf[1][n]=' ';
			buf[n][1]=' ';
			buf[n][n]=' ';
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				cout<<buf[i][j];
				cout<<endl;
		
		}
	}
	return 0;
}
 
