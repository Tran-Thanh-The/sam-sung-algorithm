#include <bits/stdc++.h>
using namespace std;

bool cmp( pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		int n;
		cin >> n;

		pair<int, int> a[n];
		
		for ( int i = 0; i < n; ++i) {
			cin >> a[i].first >> a[i].second;
		}
		
		sort( a, a+n, cmp);
		
		int res = 1, temp = 0;
		for ( int i = 1; i < n; ++i) {
			if ( a[i].first >= a[temp].second) {
				++ res;
				temp = i;
			}
		}
		cout << res << endl;
	}
	return 0;
}

