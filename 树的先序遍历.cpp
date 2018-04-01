//辉哥，以下代码我是学习您的树的视频敲的
//问题：您基础知识视频中第二节在14:10中原话是"通过指向某个结构体的指针取结构体的分量不能用点 "
//可是我下面遇到了这种情况，分别在22行 36,37行，貌似我有点矛盾了，很期待您的解答 
#include<stdio.h> 
#include<stdlib.h>
#define maxSize 50
typedef struct Branch{
	int cidx;
	Branch *next;
}Branch;
typedef struct{
	int  data;
	Branch *first;
}TNode; 
void visit(TNode *bt){
	printf("%d\n",bt->data);
}
void preOrder(TNode *p,TNode tree[]){//树的先序遍历 
	if(p!=NULL){
		visit(p);
		Branch *q;
		q=p->first;//显然这里用p.first是错的 ？？？？？ 
		while(q!=NULL){
			preOrder(&tree[q->cidx],tree);
			q=q->next;
		} 
	}
}
void level(TNode *tn,TNode tree[]){//层次遍历 
	int front,rear;
	TNode *que[maxSize];
	front=rear=0;
	TNode *p;
	if(tn!=NULL){
		rear=(rear+1)%maxSize;
		que[rear]=tn;
		while(front!=rear){
			front=(front+1)%maxSize;
			p=que[front];
			visit(p);
			Branch *q=p->first; //0出队后紧接着循环子节点1、2、3依次入队，
								//1出对，紧接着循环子节点4、5进队以此进行下去 
			while(q!=NULL){
				rear=(rear+1)%maxSize;
				que[rear]=&tree[q->cidx];
				q=q->next;
			} 
		} 
	} 
}
int main(){
	//初始化 
	//	   0
	//	  /|\
	//  1  2 4
	// /| 
	//4	5 
	TNode tree[6];//定义TNode *tree[6] ，下面初始化为tree->data,用箭头 ？？？？ 
	tree[0].data=0;tree[1].data=1;tree[2].data=2;tree[3].data=3;tree[4].data=4;tree[5].data=5;//数据域 
	Branch *b1,*b2,*b3,*b4,*b5;//可以看成 
	b1=(Branch*)malloc(sizeof(Branch));b2=(Branch*)malloc(sizeof(Branch));b3=(Branch*)malloc(sizeof(Branch));
	b4=(Branch*)malloc(sizeof(Branch));b5=(Branch*)malloc(sizeof(Branch));
	tree[0].first=b1;b1->cidx=1;b1->next=b2;b2->cidx=2;b2->next=b3;b3->cidx=3;b3->next=NULL;
	tree[1].first=b4;b4->cidx=4;b4->next=b5;b5->cidx=5;b5->next=NULL;
	tree[2].first=NULL;tree[3].first=NULL;tree[4].first=NULL;tree[5].first=NULL;
	preOrder(&tree[0],tree);
	level(&tree[0],tree);
	return 0;
} 
