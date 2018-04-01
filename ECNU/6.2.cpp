#include<stdio.h> 
#include<stack>
#include<iostream>
#include<queue>
using namespace std;
bool mark[50][50][50];
int maze[50][50][50];
struct N{
	int x,y,z;
	int t;
};
int way[][3]={
	0,0,1,
	0,1,0,
	1,0,0,
	-1,0,0,
	0,-1,0,
	0,0,-1
};
queue<N> Q;
int bfs(int a,int b,int c){
	while(Q.empty()==false){
		N now=Q.front();
		Q.pop();
		for(int i=0;i<6;i++){
			int nx=way[i][0]+now.x;
			int ny=way[i][1]+now.y;
			int nz=way[i][2]+now.z;
			if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)continue;
			if(mark[nx][ny][nz]==true)continue;
			if(maze[nx][ny][nz]==1)continue;
			N tmp;
			tmp.x=nx;
			tmp.y=ny;
			tmp.z=nz;
			tmp.t=now.t+1;
			Q.push(tmp);
			mark[nx][ny][nz]=true;
			if(nx==a-1&&ny==b-1&&nz==c-1)return tmp.t;
		}
	}
	return -1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,t;
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					mark[i][j][k]=false;
					cin>>maze[i][j][k];
				}
			}
		} 
		while(Q.empty()==false)Q.pop();
		mark[0][0][0]=true;
		N tmp;
		tmp.t=tmp.y=tmp.x=tmp.z=0;
		Q.push(tmp);
		int res=bfs(a,b,c);
		if(res<=t)cout<<res;
		else cout<<-1; 
	}
	return 0;
}

