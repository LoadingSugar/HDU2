#include <iostream>  
using namespace std;   
#define MAX 20  
int res_num;  
// 因子暂存在res数组中  
int res[MAX];  
int p = 0;  

// 将n进行分解  
void resolve(int n, int min_factor=1);  

int main() {  
    while (1) {  
        int n;  
        cin >> n;  
        resolve(n,1);  
        cout<< res_num << endl;  
        res_num = 0;  
    }  
    return 0;  
}  

void resolve(int n, int min_factor) {  
    if (n<=0) { // 出口   
        res_num++;  
    }  

    for (int i=min_factor; i<=n; i++) {     // 此处修改  
        res[p] = i;  
        p++;        // p_res++来顺次存储各个因子  
        resolve(n-i, i);// 此处修改  
        p--;        // 此行必须有，执行完上一行，下一次for循环即使第一个因子  
    }  
}  
