#include<stdio.h>
//ϣ������
void shellSort(int arr[],int n){
	int temp;
	for(int gap=n/2;gap>0;gap/=2){
		for(int j=gap;j<n;j++){
			temp=arr[j];
			int i;
			for(i=j;i>=gap&&temp<arr[i-gap];i-=gap)//�˴�i������i>=0; 
				arr[i]=arr[i-gap];
			arr[i]=temp;
		}
	}
} 
//��������
void quick(int arr[],int low,int high){
	int temp;
	int	i=low,j=high;
	if(low<high){
		temp=arr[low];
		while(j>i&&arr[j]>temp)j--;
		if(i<j){
			arr[i]=arr[j];
			i++;//��j-- 
		}
		while(j>i&&arr[i]<temp)i++;
		if(i<j){
			arr[j]=arr[i];
			j--;//��i++ 
		}
		arr[i]=temp;//i��j����ȵ� 
		quick(arr,low,i-1);
		quick(arr,i+1,high);
	}
} 
int main(){
	int a[10]={78,3,56,20,34,36,76,1,32,90};
	shellSort(a,10);
	for(int i=0;i<10;i++)
		printf("%d\t",a[i]);	
}
