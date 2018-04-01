#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define maxn 10001
#define INF 102983983267867213
int dp[maxn];
int L[maxn];
int L1,L2,L3,C1,C2,C3,a,b,n;
int cost(int n1,int n2){
    if(abs(n1-n2)<=L1)return C1;
    if(abs(n1-n2)<=L2)return C2;
    else return C3;
}
int main(){
    while(scanf("%d %d %d %d %d %d",&L1,&L2,&L3,&C1,&C2,&C3)!=EOF){
        scanf("%d%d",&a,&b);
        scanf("%d",&n);
        int i;
        for(i=2;i<=n;i++){
            scanf("%d",&L[i]);
        }
        L[1]=0;
        for(i=0;i<maxn;i++)
            dp[i]=INF;
        dp[a]=0;
        for(int i=a;i<=b;i++){
            for(int j=i+1;j<=b&&L[j]-L[i]<=L3;j++){
                dp[j]=min(dp[j],dp[i]+cost(L[i],L[j]));
            }
        }
        printf("%d\n",dp[b]);
    }

    return 0;
}
