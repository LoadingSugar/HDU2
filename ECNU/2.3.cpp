#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string>
#include<iostream> 
using namespace std;
#define isyeap(x) x%100!=0&&x%4==0||x%400==0?1:0
int dayMouth[13][2]={
	0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};
struct Date{
	int day;
	int mouth;
	int year;
	void nextday(){
		if(day+1>dayMouth[mouth][isyeap(year)]){
			if(mouth+1>12) {year++;mouth=1;day=1;}
			else {mouth++;day=1;}
		}
		else
			day++ ;
	
	}
};
int abs(int a,int b){
	return a-b>0?a-b:b-a;
}
int buf[5001][13][32];
int main(){
	int num=0;
	Date t;
	t.day=1;t.mouth=1;t.year=0;
	while(t.year!=5001){
		buf[t.year][t.mouth][t.day]=num;
		num++;
		t.nextday();
	}
	int year,mouth,day,year2,mouth2,day2;
	while(scanf("%4d%2d%2d",&year,&mouth,&day)!=EOF){
		scanf("%4d%2d%2d",&year2,&mouth2,&day2);
		cout<<abs(buf[year][mouth][day]-buf[year2][mouth2][day2])+1<<endl;
	}
	return 0;
}
