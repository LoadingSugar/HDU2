#include<stdio.h> 
#include<stdlib.h>
#include<string>
#define maxSize 50
typedef struct BTNode{
	int data;
	BTNode *lchild;
	BTNode *rchild;
}BTNode;
void visit(BTNode *bt){
	printf("%d\n",bt->data);
}
void postorderNonrecursion(BTNode *bt){
	if(bt!=NULL){
		BTNode *Stack[maxSize];int top=-1;
		BTNode *Stack2[maxSize];int top2=-1;
		BTNode *q=NULL;
		Stack[++top]=bt;
		while(top!=-1) {
			q=Stack[top--];
			Stack2[++top2]=q;
			if(q->lchild!=NULL)Stack[++top]=q->lchild; 
			if(q->rchild!=NULL)Stack[++top]=q->rchild;
		}
		while(top2!=-1){
			q=Stack2[top2--];
			visit(q);
		} 
	}
}
void postorder(BTNode *p){
	if(p!=NULL){
		
		postorder(p->lchild);
		postorder(p->rchild);
		visit(p);
	}
}
//³õÊ¼»¯ 
int main(){
//	  1
//  2	3
//4	5	  6
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
	postorder(T);
	puts("---------------------");
	postorderNonrecursion(T);
	return 0;
} 
