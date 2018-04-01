#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<iostream> 
using namespace std;
struct stu{
	char num[10];
	char name[10];
	char sex[10];
	int age;
	bool operator < (const stu &A) const{
		return strcmp(num,A.num)<0;
	}
}buf[1000];
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			scanf("%s%s%s%d",buf[i].num,buf[i].name,buf[i].sex,&buf[i].age);
		} 
		sort(buf,buf+n);
		int t;
		cin>>t;
		while(t--!=0){
			int ans=-1;
			char total[10];
			cin>>total;
			int base=0,top=n-1,mid;
			while(top>=base){
				mid=(top+base)/2;
				int temp=strcmp(total,buf[mid].num);
				if(temp==0){ans=mid;break;}
				if(temp>0){base=mid+1;}
				else top=mid-1;
			}
			if(ans==-1)cout<<"No Answer!\n";
			else printf("%s %s %s %d\n",buf[ans].num,buf[ans].name,buf[ans].sex,buf[ans].age);
		}
	}
	return 0;
} 

