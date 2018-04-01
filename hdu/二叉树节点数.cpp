#include <iostream>
#include<stdio.h>
using namespace std;
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BiNode, *BiTree;
// ������������ ������ʱ���������������������н���ֵ,�� # �ַ���ʾ������
BiTree createBiTree()
{
    BiTree T;
    char c;
    scanf("%c", &c);
    if (c == '#')
        T = NULL;
    else
    {
        T = new BiNode;  // �� T = (BiTree)malloc(sizeof(BiNode));
        T->data = c;

        T->lchild = createBiTree();
        T->rchild = createBiTree();
    }
    return T;
}
// ǰ�����
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        printf("%c\n", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
// ������Ҷ�ӽڵ�������ݹ鷽����
int leaf_num(BiTree T)
{
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    return (leaf_num(T->lchild) + leaf_num(T->rchild));
}
int main(int argc, const char * argv[]) {
    BiTree T = createBiTree(); // ����
    PreOrderTraverse(T); // ���
    int num = leaf_num(T);
    printf("%d\n", num);
    return 0;
}


//���鼯
int Tree[N];
int findRoot(int x){
	if(Tree[x]==1)return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int main()
{
	/* code */
	int n,m;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);
		for(int i=0;i<n;i++)Tree[i]=-1;
		while(m--!=0){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)Tree[a]=b;
			int ans=0;
			for(int i=1;i<=n;i++)
				if(Tree[i]==-1)ans++;
			printf("%d\n",ans);
		}

	}
	return 0;
}