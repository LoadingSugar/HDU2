#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#define N 10 
#define LEN 81
#define Element_type int
typedef struct{
	int x;
	int y;
	char s[100];
}SNode;


void fun1(int n) {
	if(n==0){//在二进制前面多加了一个0 
		printf("%d",n);return;
	}
	if(n>0){
		fun1(n/2);
		printf("%d",n%2);
	}
}

int  judge(int k[],int a[],int b[],int c[]){
	int x1=0,x2=0,x3=0;
	for(int i=0;i<10;i++){
		if(k[i]==a[i])x1++;
		if(k[i]==b[i])x2++;
		if(k[i]==c[i])x3++;
	}
	if(x1==7&&x2==7&&x3==7)return 1;
	else return 0;
} 
void test(int k[],int a[],int b[],int c[],int n){
	if(n==0&&judge(k,a,b,c))for(int i=0;i<10;i+b){
		k[n]=0;
		test(k,a,b,c,n+1);
		n--;
		k[n]=1;
		test(k,a,b,c,n+1);
		//n--;
	}

}
int comp(const void*a,const void*b)//空指针 
{
//return *(int*)a>*(int*)b?1:-1;
//*(int*)a，a是一个指针，再将a转换成int类型的指针，再取指针所指的值 
return *(int *)a-*(int *)b;
}
int Comp(const void *p1,const void *p2)
{
return strcmp((char *)p1,(char *)p2);//小的话就是-1，大的话就是1------------增序 
}
int Comp3(const void*a,const void*b)
	{return         *((Element_type *)a)>*((Element_type *)b)?1:-1;}// 
	//*((Element_type *)a)取得是一维数组的值 
int comp1(const void*a,const void*b)
	{return strlen( *((char (*)[LEN])b) )-strlen(*(char (*)[LEN])a);}//二维比较 
	//*((char (*)[LEN])b)取得还是地址   (char (*)[LEN])强制转换并且控制第二维的长度 
int comp2(const void*a,const void*b)
	{return strcmp( *((char (*)[LEN])a),*((char (*)[LEN])b)  );}
int comp4(const void*a,const void*b){
	//不行//
	return ((SNode *)a)->x>((SNode *)b)->x?1:-1;
	//SNode *c=(SNode *)a;
	//SNode *d=(SNode *)b;
	//return (c->x>d->x)?1:-1;
	}
int comp5(const void *a,const void *b){
	return strcmp( ((SNode *)a)->s,((SNode *)b)->s );
	}
int main(){
	//fun1(0);
	SNode nod[3];
	nod[0]={3,2,}; nod[1]={2,1,}; nod[2]={1,1,}; 
	strcpy(nod[0].s,"bllo");strcpy(nod[1].s,"allo");strcpy(nod[2].s,"zllo");
	for(int i=0;i<3;i++){
		printf("%d,%d,%s\n",nod[i].x,nod[i].y,nod[i].s);
	}
	qsort(nod,3,sizeof(SNode),comp5);
	for(int i=0;i<3;i++){
		printf("%d,%d,%s\n",nod[i].x,nod[i].y,nod[i].s);
	}
	printf("%d\n",nod[1].x);
	int i;
	char st[N][LEN]; strcpy(st[0],"BASIC");
	strcpy(st[1],"FORTRAN");strcpy(st[2],"C");strcpy(st[3],"C++");
	strcpy(st[4],"JAVA");strcpy(st[5],"C#");
	strcpy(st[6],"PERL");strcpy(st[7],"PASCAL");
	qsort(st,8,sizeof(char[LEN]),comp1);
	for(i=0;i<8;i++)printf("%s ",st[i]);printf("\n");
	qsort(st,8,sizeof(char[LEN]),comp2);
	for(int i=0;i<8;i++)printf("%s ",st[i]);printf("\n");
	int k[10]={0},a[10]={4,5,6,10,2,3,1,56,32,16} ;
	qsort(a,10,sizeof(int),Comp3);
	char j[3][4];
	strcpy(j[0],"abc");strcpy(j[1],"bbc");strcpy(j[2],"cbc");
	qsort(j,3,sizeof(j[0]),Comp3);                            
	for(int i=0;i<3;i++)printf("%s\n",j[i]);
	//j[0]="123";
	for(int i=0;i<10;i++)printf("%d\t",a[i]);
	//printf("%d\n",t);
	return 1;
}
