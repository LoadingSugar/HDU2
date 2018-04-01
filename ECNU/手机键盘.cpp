#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<char,int> m;
	m.insert(make_pair('a',1));
	m.insert(make_pair('d',1));
	m.insert(make_pair('g',1));
	m.insert(make_pair('j',1));
	m.insert(make_pair('m',1));
	m.insert(make_pair('p',1));
	m.insert(make_pair('t',1));
	m.insert(make_pair('w',1));
	m.insert(make_pair('b',2));
	m.insert(make_pair('e',2));
	m.insert(make_pair('h',2));
	m.insert(make_pair('k',2));
	m.insert(make_pair('n',2));
	m.insert(make_pair('q',2));
	m.insert(make_pair('u',2));
	m.insert(make_pair('x',2));
	m.insert(make_pair('c',3));
	m.insert(make_pair('f',3));
	m.insert(make_pair('i',3));
	m.insert(make_pair('l',3));
	m.insert(make_pair('o',3));
	m.insert(make_pair('r',3));
	m.insert(make_pair('v',3));
	m.insert(make_pair('y',3));
	m.insert(make_pair('s',4));
	m.insert(make_pair('z',4));
	map<char,int> p;
	p.insert(make_pair('a',0));
	p.insert(make_pair('d',1));
	p.insert(make_pair('g',2));
	p.insert(make_pair('j',3));
	p.insert(make_pair('m',4));
	p.insert(make_pair('p',5));
	p.insert(make_pair('t',6));
	p.insert(make_pair('w',7));
	p.insert(make_pair('b',0));
	p.insert(make_pair('e',1));
	p.insert(make_pair('h',2));
	p.insert(make_pair('k',3));
	p.insert(make_pair('n',4));
	p.insert(make_pair('q',5));
	p.insert(make_pair('u',6));
	p.insert(make_pair('x',7));
	p.insert(make_pair('c',0));
	p.insert(make_pair('f',1));
	p.insert(make_pair('i',2));
	p.insert(make_pair('l',3));
	p.insert(make_pair('o',4));
	p.insert(make_pair('r',5));
	p.insert(make_pair('v',6));
	p.insert(make_pair('y',7));
	p.insert(make_pair('s',5));
	p.insert(make_pair('z',7));
	char s[4];
	while(cin>>s){
		int sum=0;
		for(int i=0;i<3;i++){
			map<char, int>::iterator it = m.find(s[i]);
			sum+=it->second;
    	}
    	map<char, int>::iterator i1 = p.find(s[0]);
		map<char, int>::iterator i2 = p.find(s[1]);
		map<char, int>::iterator i3 = p.find(s[]);
		if(i1->second==i2->second)sum+=2;
		if(i2->second==i3->second)sum+=2;
    	cout<<sum<<endl;
    
	} 
    return 0;
}
