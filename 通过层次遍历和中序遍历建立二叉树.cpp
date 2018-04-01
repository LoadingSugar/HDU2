#include<stdio.h>
#include<stdlib.h>
#define maxSize 50
//层次遍历和中序遍历建立二叉树
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
//寻找层次遍历中的root在中序遍历的第几个 
int search(char arr[],char key,int L,int R){
	for(int i=L;i<=R;i++)
		if(key==arr[i])
			return i;
	return -1;
}
void getSublevel(char sublevel[],char level[],char in[],int n,int L,int R){
	int k=0;
	for(int i=0;i<n;i++){
		if(search(in,level[i],L,R)!=-1)
			sublevel[k++]=level[i];
	}
}
BTNode* CreateBT(char level[],char in[],int n,int L,int R){
	if(L>R)return NULL; 
	BTNode *s=(BTNode*)malloc(sizeof(BTNode));
	s->lchild=NULL;s->rchild=NULL;
	s->data=level[0];
	int i=search(in,level[0],L,R);
	int LN=i-L;char Llevel[LN];
	int RN=R-i;char Rlevel[RN];
	getSublevel(Llevel,level,in,n,L,i-1); 
	getSublevel(Rlevel,level,in,n,i+1,R);
	s->lchild=CreateBT(Llevel,in,LN,L,i-1);
	s->rchild=CreateBT(Rlevel,in,RN,i+1,R);
	return s;
}
int main(){
	char level[]="ABCDEFGH";
	char in[]="DBEACGFH";
	BTNode *bt;
	bt=CreateBT(level,in,8,0,8);
	preErgodic(bt);
}
