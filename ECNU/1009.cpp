#include <iostream>  
using namespace std;   
#define MAX 20  
int res_num;  
// �����ݴ���res������  
int res[MAX];  
int p = 0;  

// ��n���зֽ�  
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
    if (n<=0) { // ����   
        res_num++;  
    }  

    for (int i=min_factor; i<=n; i++) {     // �˴��޸�  
        res[p] = i;  
        p++;        // p_res++��˳�δ洢��������  
        resolve(n-i, i);// �˴��޸�  
        p--;        // ���б����У�ִ������һ�У���һ��forѭ����ʹ��һ������  
    }  
}  
