#include<stdio.h> 
#include<stdlib.h>
#define maxSize 50
typedef struct BTNode{
	int data;
	BTNode *lchild;
	BTNode *rchild;
}BTNode;
void visit(BTNode *bt){
	printf("%d\n",bt->data);
}
void inorderNonrecursion(BTNode *bt){
	if(bt!=NULL){
		BTNode *Stack[maxSize];int top=-1;
		//BTNode *Stack2[maxSize];int top2=-1;
		BTNode *p=NULL;
		p=bt;
		while(top!=-1||p!=NULL){
			while(p!=NULL){
				Stack[++top]=p;
				p=p->lchild; //只有中序遍历用到p传p，
				//like 先序遍历，后续遍历,层次遍历基本都是通过栈顶层赋值给p 
			}
			if(top!=-1){
				p=Stack[top--];
				visit(p);
				p=p->rchild;
			}
		}
		
	}
}
void preorder(BTNode *p){
	if(p!=NULL){
		visit(p);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
//初始化 
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
	preorder(T);
	inorderNonrecursion(T);
	return 0;
} 
