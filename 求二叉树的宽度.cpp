#include<stdio.h>
#include<stdlib.h>
#define maxSize 50
typedef struct BTNode{
	int data;
	BTNode *lchild;
	BTNode *rchild; 
} BTNode;
typedef struct{
	BTNode *p;
	int lno;
}st;
int maxNode(BTNode *b){
	st que[maxSize];
	int front,rear;
	rear=front=0;
	int i,j,n,max;
	BTNode *q;
	if(b!=NULL){
		rear++;
		que[rear].p=b;
		que[rear].lno=1;
		while(rear!=front){
			front++;
			q=que[front].p;
			//Lno=que[front].lno;
			if(q->lchild!=NULL){
				rear++;
				que[rear].p=q->lchild;
				que[rear].lno=que[front].lno+1; 
			}
			if(q->rchild!=NULL){
				rear++;
				que[rear].p=q->rchild;
				que[rear].lno=que[front].lno+1; 
			}
		}
		max=0;
		for(i=1;i<=que[rear].lno;i++){
			n=0;
			for(j=1;j<=rear;j++)
				if(que[j].lno==i)n++; 
			if(n>max)max=n;
		}
		return max;
	}
	else return 0;
}
//	  1
//  2	3
//4	5	  6
int main(){
	BTNode *T,*Tl,*Tr,*Tl1,*Tl2,*Tr1;
	T=(BTNode*)malloc(sizeof(BTNode));
	Tl=(BTNode*)malloc(sizeof(BTNode));
	Tr=(BTNode*)malloc(sizeof(BTNode));
	Tl1=(BTNode*)malloc(sizeof(BTNode));
	Tl2=(BTNode*)malloc(sizeof(BTNode));
	Tr1=(BTNode*)malloc(sizeof(BTNode));
	T->data=1;Tl->data=2;Tr->data=3;Tl1->data=4;Tl2->data=5;Tr1->data=6;
	T->lchild=Tl;T->rchild=Tr;Tl->lchild=Tl1;Tl->rchild=Tl2;Tr->lchild=Tr1;
	Tl1->lchild=NULL;Tl2->lchild=NULL;Tr1->lchild=NULL;Tr->rchild=NULL;
	Tl1->rchild=NULL;Tl2->rchild=NULL;Tr1->rchild=NULL;
	printf("%d",maxNode(T));
	
}
