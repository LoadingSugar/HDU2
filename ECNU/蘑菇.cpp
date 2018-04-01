#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1005], b[1005];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
    }
    int A, B, ans1 = 0, ans2 = 0;
    scanf("%d %d", &A, &B);
    memcpy(a, b, sizeof(a));
    for(int i = 2; i <= n - 1; ++i) {
        int c = a[i - 1] / B;
        if(a[i - 1] % B != 0) ++c;
        ans1 += c;
        a[i - 1] = 0;
        a[i] -= c * A;
        if(a[i] < 0) a[i] = 0;
        a[i + 1] -= c * B;
        if(a[i + 1] < 0) a[i + 1] = 0;
    }
    if(a[n] > 0) {
        ans1 += (a[n] % B == 0) ? a[n] / B : a[n] / B + 1;
    }
    memcpy(a, b, sizeof(a));
    for(int i = n - 1; i >= 2; --i) {
        int c = a[i + 1] / B;
        if(a[i + 1] % B != 0) ++c;
        ans2 += c;
        a[i + 1] = 0;
        a[i] -= c * A;
        if(a[i] < 0) a[i] = 0;
        a[i - 1] -= c * B;
        if(a[i - 1] < 0) a[i - 1] = 0;
    }
    if(a[1] > 0) {
        ans2 += (a[1] % B == 0) ? a[1] / B : a[1] / B + 1;
    }
    printf("%d\n", min(ans1, ans2));
    return 0;
}

