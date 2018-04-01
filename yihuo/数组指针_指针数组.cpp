#include<stdio.h> 
int main(){
	//指针数组 
	int *p[3];
	int a[3][4]={1,2,3,4,
				5,6,7,8,
				9,10,1,1};
	//p++; //该语句表示p数组指向下一个数组元素。
	//注：此数组每一个元素都是一个指针
	*p=a[0];
	printf("%d        \n",*p); 
	for(int i=0;i<3;i++){ 
		*(p+i)=a[i];
		for(int j=0;j<4;j++)
		printf("----%d\n",*(p[i]++)); //*(*(p+i)+1)
	} 
	//数组指针
	int (*q)[4];
	int **k;
	k=&p[1];//q=&p[1]报错 
	//k=a;//错误    应该是*k=*a 
	q=a; //等价于q=&a[0] 
	for(int j=0;j<4;j++){
		printf("%d\n",*(*(q+1)+j));
	}
}
