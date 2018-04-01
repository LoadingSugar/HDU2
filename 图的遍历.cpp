#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include <iostream>
#include <typeinfo>
using namespace std;
#include<string>
#define maxSize 50
//边 
typedef struct ArcNode{
	int adjv;
	struct ArcNode *next;
} ArcNode;
//结点 
typedef struct{
	int data;
	ArcNode* first;
}VNode;
typedef struct{
	VNode adjList[maxSize];
	int n,e;
}AGraph;
AGraph gp;
int visit[maxSize];
void Visit(int v){
	printf("%d\n",gp.adjList[v].data);
}
//深度优先遍历 
void DFS(int v,AGraph *G){
	visit[v]=1;
	Visit(v);
	ArcNode* q=G->adjList[v].first;
	while(q!=NULL){
		if(visit[q->adjv]==0)
			DFS(q->adjv,G);
		q=q->next; 
	}	
} 
//广度优先遍历
void BFS(AGraph *G,int v,int visit[maxSize]){
	ArcNode *p;
	int que[maxSize],rear=0,front=0;
	int j;
	Visit(v);
	visit[v]=1;
	rear=(rear+1)%maxSize;
	que[rear]=v;
	while(front!=rear){
		front=(front+1)%maxSize;
		j=que[front];
		p=G->adjList[j].first;
		while(p!=NULL){
			if(visit[p->adjv]==0){
				Visit(p->adjv);
				visit[p->adjv]=1;
				rear=(rear+1)%maxSize;
				que[rear]=p->adjv; 
			}
			p=p->next; 
		} 
		
	}
}
int main(){
	//邻接表存储方式 
	for(int i=0;i<maxSize;i++)visit[i]=0;
	gp.e=6;gp.n=5;
	gp.adjList[0].data=0,gp.adjList[1].data=1,gp.adjList[2].data=2,gp.adjList[3].data=3,gp.adjList[4].data=4;	
	ArcNode *a1,*a2,*a3,*a4,*a5,*a6;
	a1=(ArcNode*)malloc(sizeof(ArcNode)),a2=(ArcNode*)malloc(sizeof(ArcNode)),a3=(ArcNode*)malloc(sizeof(ArcNode)),a4=(ArcNode*)malloc(sizeof(ArcNode)),a5=(ArcNode*)malloc(sizeof(ArcNode)),a6=(ArcNode*)malloc(sizeof(ArcNode));
	a1->adjv=1,a1->next=NULL,a2->adjv=4,a2->next=NULL,a3->adjv=0,a3->next=NULL,a4->adjv=0,a4->next=NULL,a5->adjv=2,a5->next=a6,a6->adjv=3,a6->next=NULL; 
	gp.adjList[0].first=a1,gp.adjList[1].first=a2,gp.adjList[2].first=a3,gp.adjList[3].first=a4,gp.adjList[4].first=a5;
	DFS(0,&gp);
	puts("---------------");for(int i=0;i<maxSize;i++)visit[i]=0;
	BFS(&gp,0,visit);
}
