#include <iostream>
#include <algorithm>
#include<string.h> 
#include<stdio.h> 
using namespace std;
///////////////////////////SubMain//////////////////////////////////
int main()
{
	int n=460897024;
int factor = 2  ;
int lastFactor = 1  ;
  
while(n > 1) {
    if( n % factor==0){    
        lastFactor = factor ;  
        n = n/factor  ;
        while (n % factor==0){
            n = n / factor ;}}
    factor = factor + 1    ;

}
cout<<lastFactor;  
}
