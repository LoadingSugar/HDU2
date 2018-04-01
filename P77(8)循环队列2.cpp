#include<stdio.h> 
#include<stdlib.h>
typedef struct{
	int data[maxSize];
	int front;
	int fear;
	int tag;
}Queue;
void initQueue(Queue &q){
	q=(Queue*)malloc(sizeof(Queue));
	q.front=q.rear=0;
	tag=0;
}
int isEmpty(Queue q){
	if(q.fear==q.front&&q.tag==0)return 1;
	else return 0;
}
int isFull(Queue q){
	if(q.front==q.rear&&q.tag==1)return 1;
	else return 0;
}
int enQueue(Queue &q,int x){
	if(isFull(q))return 0;
	else{
		p.rear=(p.rear+1+maxSize)%maxSize;
		p.data[p.rear]=x;
		p.tag=1;
		return 1;
	}
}
int deQueue(Queue &q,int &x){
	if(isEmpty(q))return 0;
	else{
		q.front=(q.front+1+maxSize)%maxSize;
		x=q.data[q.front];
		q.tag=0;
		return 1;
	} 
}

