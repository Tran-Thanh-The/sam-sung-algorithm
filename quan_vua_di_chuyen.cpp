#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int l1 = abs(x1-x2), l2 = abs(y1-y2);
	cout << max ( l1, l2);
	return 0;
}

