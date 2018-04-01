#include<stdio.h>
#include<stdlib.h>
#define maxSize 50
typedef struct ArcNode{
	int adjv;
	struct ArcNode* next;
}ArcNode;
typedef struct {
	int data;
	int count;//该顶点的入度 
	ArcNode* first;
}VNode;
typedef struct{
	int n,e;
	VNode adjList[maxSize];
}AGraph;
int TopSort(AGraph *G){
	int i,j,n=0;
	int stack[maxSize],top=-1;
	ArcNode *p;
	for(i=0;i<G->n;i++)
		if(G->adjList[i].count==0)stack[++top]=i;
	while(top!=-1){
		i=stack[top--];
		++n;
		printf("%d\t",i); 
		p=G->adjList[i].first;
		while(p!=NULL){
			j=p->adjv;
			--(G->adjList[j].count);
			if(G->adjList[j].count==0)
				stack[++top]=j;
			p=p->next; 
		} 
	}
	if(n==G->n)return 1;
	else return 0;
} 
int main(){
	AGraph gp;
	gp.e=4,gp.n=4;
	ArcNode *a1,*a2,*a3,*a4;
	a1=(ArcNode*)malloc(sizeof(ArcNode)),a2=(ArcNode*)malloc(sizeof(ArcNode)),a3=(ArcNode*)malloc(sizeof(ArcNode)),a4=(ArcNode*)malloc(sizeof(ArcNode));
	a1->adjv=1,a1->next=a2,a2->adjv=2,a2->next=NULL;
	a3->adjv=3,a3->next=NULL,a4->adjv=3,a4->next=NULL;
	gp.adjList[0].first=a1,gp.adjList[1].first=a3,gp.adjList[2].first=a4;
	gp.adjList[0].data=0,gp.adjList[1].data=1,gp.adjList[2].data=2,gp.adjList[3].data=3;
	gp.adjList[0].count=0,gp.adjList[1].count=1,gp.adjList[2].count=1,gp.adjList[3].count=2;
	TopSort(&gp);
	
}
