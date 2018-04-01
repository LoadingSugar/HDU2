#include<iostream>
#include<string>
#define MAX 101
int vis[MAX];
using namespace std;
string str;
int cou = 0;
string::size_type idx;
bool check(int a[], int num, int k) {
	for (int i = 0; i < num; i++) {
		if (a[i] > k) {
			return false;
		}
	}
	return true;
}
void dfs(int num, int k, int e, int arr[]) {
	/*
	k代表几个数     e代表区间
	*/
	if (num >= k) {
		int flag = 1;
		for (int i = 0; i < k - 1; i++) {
			if ((idx = str.substr(arr[i], arr[i + 1] - arr[i]).find('1')) == (string::npos))
			{
				flag = 0;
				break;
			}
		}
		if ((idx = str.substr(arr[k - 1]).find('1')) == (string::npos))
			flag = 0;
		if (flag == 1) {
			for (int i = 0; i < k - 1; i++)
				cout << str.substr(arr[i], arr[i + 1] - arr[i]) << " ";
			cout << str.substr(arr[k - 1]) << endl;
			cou++;
		}
		return;
	}
	for (int i = 1; i <= e; i++) {
		if (!vis[i] && check(arr, num, i)) {
			vis[i] = 1;
			arr[num] = i;
			dfs(num + 1, k, e, arr);
			vis[i] = 0;
		}
	}
}
int main() {
	int n;
	cin >> str;
	cin >> n;
	int e = str.length() - 1;
	int *a = new int[n];
	a[0] = 0;
	dfs(1, n, e, a);
	cout << cou << endl;
}
