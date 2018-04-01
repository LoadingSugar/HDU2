#include<iostream>  
#include<algorithm>  
using namespace std;  
int cal(int x,int y,int k){
	if(y==1){
		if(x<k)return x;
		else{
			while(x>=k){
				int res=0;
				while(x){
				res+=x%k;
				x/=k;
				}
				x=res;
			}
			return x;
		}
	}
	if(y%2==1){
		return cal(cal(x,y/2,k)*cal(x,y/2,k)*cal(x,1,k),1,k);
	}
	else{
		return cal(cal(x,y/2,k)*cal(x,y/2,k),1,k);
	}
}
int main()  
{  
     int x, y, k;
    while (cin >> x >> y >> k)
    {
        cout << cal(x, y, k) << endl;
    }
    return 0;  
}  
