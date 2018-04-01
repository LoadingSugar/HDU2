#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct E{
	char name[101];
	int age;
	int score; 
};
bool cmp(E e1,E e2){
	if(e1.score!=e2.score)return e1.score<e2.score;
	int temp=strcmp(e1.name,e2.name);
	if(temp!=0)return temp<0;
	else return e1.age<e2.age; 
} 
int main(){
	int n;
	E buf[1000];
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>buf[i].name>>buf[i].age>>buf[i].score;
		}
		sort(buf,buf+n,cmp);
		for(int i=0;i<n;i++){
			cout<<buf[i].name<<' '<<buf[i].age<<' '<<buf[i].score<<endl;
		}
	}
	return 0;
}
