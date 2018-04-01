#include<stdio.h>
#include<stdlib.h>
#include<string>
#define maxSize 50
#define INF 10
//#define n 6
//邻接矩阵 
void Prim(int n,int MGraph[][6],int v0,int &sum){
	int vSet[n],lowCost[n];
	int v,h,min;
	for(int i=0;i<n;i++){
		vSet[i]=0;
		lowCost[i]=MGraph[v0][i];
	}
	v=v0;
	vSet[v]=1;
	sum=0;
	for(int j=0;j<n-1;j++){
		min=INF;
		for(int k=0;k<n;k++){
			if(vSet[k]==0&&lowCost[k]<min){
				min=lowCost[k];
				h=k;		
			}
		}
		sum+=min;
		vSet[h]=1;
		for(int q=0;q<n;q++){
			if(vSet[q]==0&&lowCost[q]>MGraph[h][q])
				lowCost[q]=MGraph[h][q];
		}
	}
	puts("输出lowCost数组");
	for(int i=0;i<n;i++)printf("%d\t",lowCost[i]);
	printf("\n"); 
}

int main(){
	//邻接表存储方式 
	int MGraph[6][6];
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			MGraph[i][j]=INF;
	MGraph[0][3]=3,MGraph[3][0]=3,MGraph[0][2]=2,MGraph[2][0]=2,MGraph[0][1]=1,MGraph[1][0]=1,MGraph[1][2]=7,MGraph[2][1]=7;
	MGraph[2][3]=6,MGraph[3][2]=6,MGraph[1][4]=8,MGraph[4][1]=8,MGraph[2][4]=4,MGraph[4][2]=4,MGraph[4][5]=9,MGraph[5][4]=9;
	MGraph[3][5]=5,MGraph[5][3]=5;
	int sum=0;
	Prim(6,MGraph,0,sum);
	printf("%d\n",sum); 
	
}
