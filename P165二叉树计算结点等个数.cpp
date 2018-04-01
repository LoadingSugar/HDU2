#include<stdio.h> 
#include<stdlib.h>
#define maxSize 50
typedef struct BTNode{
	int data;
	BTNode *lchild;
	BTNode *rchild;
	BTNode *parent;
}BTNode;
int n;
//*******************************************模板*********************************************
/*
void fun(){
	if(条件){
		骚操作；
		fun(左子树)；
		fun(右子树);
		骚操作； 
	} 
}
*/ 
 
void count(BTNode *p){
	if(p!=NULL)
	{	
		if(p->lchild==NULL&&p->rchild==NULL)n++;
		count(p->lchild);
		count(p->rchild);
	} 
} 
int count2(BTNode *p){
	int n1,n2;
	if(p==NULL)return 0;
	else if(p->rchild==NULL&&p->lchild==NULL)return 1;
	else{
		n1=count2(p->lchild);
		n2=count2(p->rchild);
		return n1+n2;
	} 
}
void link(BTNode *p,BTNode *&head,BTNode *&tail){
	if(p!=NULL){
		if(p->lchild==NULL&&p->rchild==NULL){
			if(head==NULL){
				head=p;
				tail=p;
			}else{
				tail->rchild=p;
				tail=p;
			}
		}
		else{
			link(p->lchild,head,tail);
			link(p->rchild,head,tail);
		}
	}	
}
void triBtree(BTNode *p,BTNode *q){
	if(p!=NULL){
		p->parent=q;
		q=p;
		triBtree(p->lchild,q);
		triBtree(p->rchild,q);
	}
}
void printPath(BTNode *p){
	while(p!=NULL){
		printf("%d\t",p->data);
		p=p->parent;
	}
	printf("\n");
}
void allPath(BTNode *p){
	if(p!=NULL){
		printPath(p);
		allPath(p->lchild);
		allPath(p->rchild);	
	} 
}
//满二叉树的前缀转后缀
void change(char pre[],int L1,int R1,char post[],int L2,int R2){
	if(L1<=R1){
		post[R2]=pre[L1];
		change(pre,L1+1,(L1+R1+1)/2,post,L2,(R2+L2)/2-1);//(R2+L2-1)/2 等于(R2+L2)/2-1主要是"/"问题 
		change(pre,(L1+R2+1)/2+1,R1,psot,(R2+L2)/2,R2-1);
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
	n=count2(T);
	printf("输出叶子结点个数：%d\n",n); 
	BTNode *a,*b;
	link(T,a,b);
	puts("输出叶子链表的头尾结点-----------------");
	printf("%d  %d\n",a->data,b->data);
	puts("输出b叶子节点的根路经-----------------");
	BTNode *c;c=NULL;
	triBtree(T,c);
	printPath(b);
	puts("输出所有结点根路径------------------");
	allPath(T);
	return 0;
} 
