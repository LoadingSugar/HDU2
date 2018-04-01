#include<stdio.h>
#define INF 100
void Dijkstra(int n,int MGraph[][7],int v0,int dist[],int path[]){
	int set[n];
	int min,v;
	for(int i=0;i<n;i++){
		set[i]=0;
		dist[i]=MGraph[v0][i];
		if(MGraph[v0][i]<INF)path[i]=v0;
		else path[i]=-1; 
	}
	set[v0]=1,path[v0]=-1;
	for(int i=0;i<n-1;i++){
		min=INF;
		for(int j=0;j<n;j++){
			if(set[j]==0&&min>dist[j]){
				min=dist[j];
				v=j;
			}
		}
		set[v]=1;
		for(int j=0;j<n;j++){
			if(set[j]==0&&(dist[v]+MGraph[v][j])<dist[j]){
				dist[j]=dist[v]+MGraph[v][j];
				path[j]=v;
			}
		}
	}	
}
void Floyd(int n,int GMraph[][4],int path[][4]){
	int i,j,v;
	int A[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			path[i][j]=-1;
			A[i][j]=GMraph[i][j]; 
		}
	for(v=0;v<n;v++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(A[i][j]>A[i][v]+A[v][j]){
					A[i][j]=A[i][v]+A[v][j];
					path[i][j]=v; 
				}
			}
}
//Floyd´òÓ¡×î¶ÌÂ·¾¶ 
void printPath(int u,int v,int path[][4]){
	if(path[u][v]==-1)printf("<%d,%d>",u,v);
	else{
		int mid=path[u][v];
		printPath(u,mid,path);
		printPath(mid,v,path);
	}
}
int main(){
	int MGraph[7][7],MGraph2[4][4],Path[4][4];
	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++){
			if(i==j)MGraph[i][j]=0;
			else MGraph[i][j]=INF;
		}
	MGraph[0][3]=6,MGraph[3][0]=6,MGraph[0][2]=6,MGraph[2][0]=6,MGraph[0][1]=4,MGraph[1][0]=4,MGraph[1][2]=1,MGraph[2][1]=1;
	MGraph[2][3]=2,MGraph[3][2]=2,MGraph[1][4]=7,MGraph[4][1]=7,MGraph[2][4]=6,MGraph[4][2]=6,MGraph[4][5]=1,MGraph[5][4]=1;
	MGraph[3][5]=5,MGraph[5][3]=5,MGraph[2][5]=4,MGraph[5][2]=4,MGraph[5][6]=8,MGraph[6][5]=8,MGraph[4][6]=6,MGraph[6][4]=6;
	int dist[7],path[7];
	Dijkstra(7,MGraph,0,dist,path);
	puts("Dijkstra------------------\n");
	for(int i=0;i<7;i++){
		printf("%d\t",path[i]);
	}
	puts("\nFloyd----------------------\n");
	MGraph2[0][0]=0,MGraph2[0][1]=5,MGraph2[0][2]=INF,MGraph2[0][3]=7;
	MGraph2[1][0]=INF,MGraph2[1][1]=0,MGraph2[1][2]=4,MGraph2[1][3]=2;
	MGraph2[2][0]=3,MGraph2[2][1]=3,MGraph2[2][2]=0,MGraph2[2][3]=2;
	MGraph2[3][0]=INF,MGraph2[3][1]=INF,MGraph2[3][2]=1,MGraph2[3][3]=0;
	Floyd(4,MGraph2,Path);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d\t",Path[i][j]);
		}
		printf("\n");
	}
	printPath(1,0,Path);
}
