#include<stdio.h>
#include<iostream>
#include<stack> 
#include<queue>
#include <vector>
#include<algorithm>
//#include<iterator>
using namespace std;
int main(){
	vector<int> v;
	v.push_back(100);
	v.push_back(200);
	v.push_back(300);
	v.push_back(400);
	v.push_back(500);
	vector<int>::iterator it=v.begin();
	v.erase(it);
	printf("iterator is %d\t%d\n",v[1],*it);
	sort(v.begin(),v.end());
	int j=0;
	do{
		for(int i=0;i<v.size();i++){
			printf("%d\t",v[i]);
			j++;
		}
		printf("\n");
	}while(next_permutation(v.begin(),v.end()));
	printf("\n%d",j);
	return 0;
}
