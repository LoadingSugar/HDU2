#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
 
using namespace std;
int  n;
char s[1000];
char out[1000];
int v[1000];

bool cmp(const char& a, const char &b)
{
    return (tolower(a) == tolower(b))?
        a < b: tolower(a) < tolower(b);
}

void dfs(int depth)
{
    if(depth == n)
    {
        out[depth] = '\0';
        printf("%s\n", out);
        return ; 
    }
    for(int i=0; i<n; i++)
    {
        if(!v[i])
        {    
            v[i] = 1;
            out[depth] = s[i];    
            dfs(depth + 1);
            v[i] = 0;
            
            while(i<n-1 && s[i] == s[i+1])
                i++;  //去重部分 
        }
    }
    return;
}
 
int main()
{
    //freopen("testin.txt", "r", stdin);
    //freopen("testout.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%s", s);
        n =    strlen(s);
        
        sort(s, s+n, cmp);//按照cmp排序 
        memset(v, 0, sizeof(v));
        dfs(0);
        //cout << endl;
    } 
    
    return 0;
}
