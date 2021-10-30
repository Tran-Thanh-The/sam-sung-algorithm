#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		string s;
		cin >> s;
		
		int i = 0;
		int n = s.length();
		int count = 0;
		int l = 0;
		
		while( i < n) {
			if ( s[i] == '(') {
				if ( l+1 <= n-i-1) {
					++ l;
				} else {
					-- l;
					++ count;
				}
			} else {
				if ( l == 0) {
					++ count;
					++ l;
				} else {
					-- l;
				}
			}
			++ i;
		}
		cout << count << endl;
	}
	return 0;
}

