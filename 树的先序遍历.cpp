//�Ը磬���´�������ѧϰ����������Ƶ�õ�
//���⣺������֪ʶ��Ƶ�еڶ�����14:10��ԭ����"ͨ��ָ��ĳ���ṹ���ָ��ȡ�ṹ��ķ��������õ� "
//��������������������������ֱ���22�� 36,37�У�ò�����е�ì���ˣ����ڴ����Ľ�� 
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
void preOrder(TNode *p,TNode tree[]){//����������� 
	if(p!=NULL){
		visit(p);
		Branch *q;
		q=p->first;//��Ȼ������p.first�Ǵ�� ���������� 
		while(q!=NULL){
			preOrder(&tree[q->cidx],tree);
			q=q->next;
		} 
	}
}
void level(TNode *tn,TNode tree[]){//��α��� 
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
			Branch *q=p->first; //0���Ӻ������ѭ���ӽڵ�1��2��3������ӣ�
								//1���ԣ�������ѭ���ӽڵ�4��5�����Դ˽�����ȥ 
			while(q!=NULL){
				rear=(rear+1)%maxSize;
				que[rear]=&tree[q->cidx];
				q=q->next;
			} 
		} 
	} 
}
int main(){
	//��ʼ�� 
	//	   0
	//	  /|\
	//  1  2 4
	// /| 
	//4	5 
	TNode tree[6];//����TNode *tree[6] �������ʼ��Ϊtree->data,�ü�ͷ �������� 
	tree[0].data=0;tree[1].data=1;tree[2].data=2;tree[3].data=3;tree[4].data=4;tree[5].data=5;//������ 
	Branch *b1,*b2,*b3,*b4,*b5;//���Կ��� 
	b1=(Branch*)malloc(sizeof(Branch));b2=(Branch*)malloc(sizeof(Branch));b3=(Branch*)malloc(sizeof(Branch));
	b4=(Branch*)malloc(sizeof(Branch));b5=(Branch*)malloc(sizeof(Branch));
	tree[0].first=b1;b1->cidx=1;b1->next=b2;b2->cidx=2;b2->next=b3;b3->cidx=3;b3->next=NULL;
	tree[1].first=b4;b4->cidx=4;b4->next=b5;b5->cidx=5;b5->next=NULL;
	tree[2].first=NULL;tree[3].first=NULL;tree[4].first=NULL;tree[5].first=NULL;
	preOrder(&tree[0],tree);
	level(&tree[0],tree);
	return 0;
} 
