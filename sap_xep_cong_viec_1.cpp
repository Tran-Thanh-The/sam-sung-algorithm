#include <bits/stdc++.h>
using namespace std;

struct Job {
	int begin, end;
};

bool cmp( struct Job a, struct Job b) {
	return a.end < b.end;
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
		struct Job a[n];
		for ( int i = 0; i < n; i++)
			cin >> a[i].begin;
		for ( int i = 0; i < n; i++)
			cin >> a[i].end;
		
		sort( a, a+n, cmp);
		
		int count = 1, temp = 0;
		for ( int i = 1; i < n; i++) {
			if ( a[i].begin >= a[temp].end) {
				++ count;
				temp = i;
			}
		}
		
		cout << count << endl;
	}
	return 0;
}

