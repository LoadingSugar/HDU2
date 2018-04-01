#include<iostream> 
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	char a[82];
	gets(a);
	for(int i=0;a[i]!='\0';i++){
		if(('a'<=a[i]&&a[i]<'z')||('A'<=a[i]&&a[i]<'Z')){printf("%c",a[i]+1);continue;}
		if(a[i]=='Z')cout<<'A';
		else if(a[i]=='z')cout<<'a';
		else cout<<a[i];
	} 
	cout<<endl;
	return 0;
}
