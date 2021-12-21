#include <bits/stdc++.h>
using namespace std;

int main() {
	char now, last;
	int count = 1, max = 1;
	
	cin >> last;
	while (cin >> now) {
		if (now != last) {
			if (count > max) {
				max = count;
			}
			count = 1;
		}
		else count++;
		last = now;
	}
	if (count > max) {
		max = count;
	}
	cout << max << '\n';

	return 0;
}
