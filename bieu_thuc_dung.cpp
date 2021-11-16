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
		stack<char> st;
		int m = 0;
		
		for ( int i = 0; i < s.length(); i++) {
			if ( s[i] == '(') {
				st.push(s[i]);
				int k = st.size();
				m = max( m, k);
			}
			else if ( s[i] == ')') {
				if ( st.size() > 0) {
					st.pop();
				}
				else {
					m = -1;
					break;
				}
			}
		}
		int k = st.size();
		if ( k > 0)
			m = -1;
		cout << m << endl;

	}
	return 0;
}

