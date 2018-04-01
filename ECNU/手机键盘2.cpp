#include <iostream>
#include <string>
using namespace std;
char getchar(char a){
	if('a'<=a && a<='c') return 'a';
    if(a>='d' && a<='f') return 'd';
    if(a>='g' && a<='i') return 'g';
    if(a>='j' && a<='l') return 'j';
    if(a>='m' && a<='o') return 'm';
    if(a>='p' && a<='s') return 'p';
    if(a>='t' && a<='v') return 't';
    if(a>='w' && a<='z') return 'w';
	return '0';
}
int main(){
	string temp;
	int sum;
	char last,now;
	while(cin>>temp){
		last='0';
		sum=0;
		for(int i=0;i<temp.length();i++){
			now=getchar(temp[i]);
			if(now!=last)
				sum+=(temp[i]-now+1);
			else
				sum+=(temp[i]-now+3);
			last=now;
		}
		cout<<sum<<endl;
	}
	return 0;
}
