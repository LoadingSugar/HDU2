#include<stdio.h> 
#include<stack>
#include<iostream>
using namespace std;
#define Bignum 10000
/*int main(){
	int p,j,k,temp;
	int n[Bignum]; 
	for(int i=0;i<=Bignum;i++){
		k=0;
		for(j=1;j<=i;j++){
			if(i%j==0)
				k++; 
		}
		n[i]=k;
	}
	while(cin>>p){
		int num[1000];
		for(int h=0;h<p;h++){
			cin>>temp;
			num[h]=n[temp];
		}
		for(int h=0;h<p;h++){
			cout<<n[h]<<endl;
		}
	}
	return 0;
}
*/
int main(){
    int n,m,ans,num;//n表示个数，m表示数值大小,ans表示因数个数
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            ans=1;
            for(int i=2;i*i<=m;i++){
                num=0;
                while(m%i==0){
                    num++;//num表示相同因子的个数               
					m=m/i;
                }
                if(num>0){
                   num++;
                   
                   ans=ans*num;
                   printf("%d\n",ans);
				}
            }
            if(m>1)ans=ans*2;
            printf("%d\n",ans);
        }  
    }
    return 0;
}
