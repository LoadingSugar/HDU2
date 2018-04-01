#include<stdio.h>
//直接插入排序 左侧有序，一次扫描右侧加入左侧
void insertSort(int arr[],int n){
	int temp,i,j;
	for(int i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0&&temp<arr[j]){//小则前移 
			arr[j+1]=arr[j];
			j--;
		} 
		arr[j+1]=temp;
	}
} 
//简单选择排序
void selectSort(int arr[],int n){//每次选择无序序列最小的放在最右边（简单选择交换） 
	int i,j,k;
	int temp;
	for(i=0;i<n;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(arr[k]>arr[j])
				k=j;
		}
		temp=arr[i];
		arr[i]=arr[k];
		arr[k]=temp;
	}
	
} 
//冒泡排序
void bubleSort(int arr[],int n){
	int i,j,temp;
	int flag;
	for(i=n-1;i>0;i--){
		flag=0;
		for(j=1;j<=i;j++){
			if(arr[j-1]>arr[j]){
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
				flag=1;
			}
		}
		if(flag==0)
		return;
	}
} 
int main(){
	int a[10]={78,3,56,20,34,36,76,1,32,90};
	//insertSort(a,10);
	//selectSort(a,10);
	bubleSort(a,10);
	for(int i=0;i<10;i++)
		printf("%d\t",a[i]);	
}
