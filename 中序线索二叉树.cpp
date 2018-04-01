//�����������Ľ������ڱ���ʱ��Ϊ�˱������������ʱ�ظ����� 
#include<stdio.h>
#include<stdlib.h>
#define maxSize 50
typedef struct TBTNode{
	int data;
	int lTag;
	int rTag;
	TBTNode *lchild;
	TBTNode *rchild; 
} TBTNode;
void visit(TBTNode *p){
	printf("%d\n",p->data);
} 
//���� 
void inThread(TBTNode *p,TBTNode *&pre){
	if(p!=NULL){
		inThread(p->lchild,pre);
		if(p->lchild==NULL){
			p->lchild=pre;
			p->lTag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rchild=p;
			pre->rTag=1;
		}
		pre=p;
		inThread(p->rchild,pre);
	}
}
//���� 
void preThread(TBTNode *p,TBTNode *&pre){
	if(p!=NULL){
		if(pre!=NULL)
		if(p->lchild==NULL){
			p->lchild=pre;
			p->lTag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rchild=p;
			pre->rTag=1; 
		}
		pre=p;
		if(p->lTag==0)
			preThread(p->lchild,pre);
		if(p->rTag==0)
			preThread(p->rchild,pre);
	}
}
//ǰ���������������
void preOrder(TBTNode *tbt){
	if(tbt!=NULL){
		TBTNode *p=tbt;
		while(p!=NULL){
			while(p->lTag==0){//��ָ�벻����������Ϊ��� 
				visit(p);
				p=p->lchild;
			}
			visit(p);
			p=p->rchild;//������ξ��Ǻ�� 
		}
	}
} 
//���� 
void postThread(TBTNode *p,TBTNode *&pre){
	if(p!=NULL){
		postThread(p->lchild,pre);
		postThread(p->rchild,pre);
		if(p->lchild==NULL){
			p->lchild=pre;
			p->lTag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			pre->rchild=p;
			pre->rTag=1;
		}
		pre=p;
	}
} 
int main(){
//	  1
//  2	3
//4	5	  6
	TBTNode *T,*Tl,*Tr,*Tl1,*Tl2,*Tr1;
	T=(TBTNode*)malloc(sizeof(TBTNode));
	Tl=(TBTNode*)malloc(sizeof(TBTNode));
	Tr=(TBTNode*)malloc(sizeof(TBTNode));
	Tl1=(TBTNode*)malloc(sizeof(TBTNode));
	Tl2=(TBTNode*)malloc(sizeof(TBTNode));
	Tr1=(TBTNode*)malloc(sizeof(TBTNode));
	T->data=1;Tl->data=2;Tr->data=3;Tl1->data=4;Tl2->data=5;Tr1->data=6;
	T->lchild=Tl;T->rchild=Tr;Tl->lchild=Tl1;Tl->rchild=Tl2;Tr->lchild=Tr1;
	Tl1->lchild=NULL;Tl2->lchild=NULL;Tr1->lchild=NULL;Tr->rchild=NULL;
	Tl1->rchild=NULL;Tl2->rchild=NULL;Tr1->rchild=NULL;
	T->lTag=0;T->rTag=0;Tl->lTag=0;Tl->rTag=0;Tr->lTag=0;//��Ҫ�Ĳ�д���� 
	TBTNode *temp=NULL;
	//temp=(TBTNode*)malloc(sizeof(TBTNode));
	preThread(T,temp);
	preOrder(T);
	return 0;
}
