#include<stdio.h>
#include<stdlib.h>
#define maxSize 50
//前序遍历和中序遍历建立二叉树
typedef struct BTNode{
	char data;
	BTNode *lchild;
	BTNode *rchild;
}BTNode;
void visit(BTNode *bt){
	printf("%c\n",bt->data); 
}
void preErgodic(BTNode *p){
	if(p!=NULL){
		visit(p); 
		preErgodic(p->lchild);
		preErgodic(p->rchild); 
	} 
} 

BTNode *CreateBT(char pre[],char in[],int L1,int R1,int L2,int R2){
	if(L1>R1)
		return NULL;
	BTNode *s=(BTNode*)malloc(sizeof(BTNode));
	s->lchild=NULL;s->rchild=NULL;
	s->data=pre[L1];
	int i;
	for(i=L2;i<R2;i++)
		if(pre[L1]==in[i])
			break;
	s->lchild=CreateBT(pre,in,L1+1,L1+i-L2,L2,i-1);
	s->rchild=CreateBT(pre,in,L1+i-L2+1,R1,i+1,R2); 
} 
//后中 建立二叉树 
BTNode *CreateBT2(char post[],char in[],int L1,int R1,int L2,int R2){
	if(L1>R1)
		return NULL;
	BTNode *s=(BTNode*)malloc(sizeof(BTNode));
	s->lchild=NULL;s->rchild=NULL;
	s->data=post[R1];
	int i;
	for(i=L2;i<R2;i++)
		if(post[R1]==in[i])
			break;
	s->lchild=CreateBT(post,in,L1,L1+i-L2-1,L2,i-1);
	s->rchild=CreateBT(post,in,L1+i-L2,R1-1,i+1,R2); 
} 
//         A
//       B   C
//     D  E    F 
//            G H 
int main(){
	char pre[]="ABDECFGH";
	char in[]="DBEACGFH";
	BTNode *bt;
	bt=CreateBT(pre,in,0,8,0,8);
	preErgodic(bt);
} 

