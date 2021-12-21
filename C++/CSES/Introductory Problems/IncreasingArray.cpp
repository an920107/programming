#include <bits/stdc++.h>
using namespace std;

int arr[200000];

int main() {
	int n, count = 0;
	cin >> n >> arr[0];
	for (int i = 1; i < n; i ++) {
		cin >> arr[i];
		while (arr[i] < arr[i - 1]) {
			arr[i] ++;
			count ++;
		}
	}
	cout << count << '\n';
	return 0;
}
