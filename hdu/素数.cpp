#include<stdio.h>
int main(){
    bool mark[100];
    for(int i=0;i<100;i++)
        mark[i]=false;
    int prim[50],num=0;
    for(int i=2;i<100;i++)
    {
        if(mark[i]==true)continue;
        prim[num++]=i;
        for(int j=i*2;j<100;j+=i){
            mark[j]=true;
        }
    }
    printf("%d\n",num);
    for(int i=0;i<num;i++)
        printf("%d ",prim[i]);
    return 0;
}
