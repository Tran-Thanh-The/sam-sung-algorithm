#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	cin.ignore(1);
	while( test--) {
		stack<char> st;
		
		string s;
		getline(cin, s);
		char check = true;
		
		for ( int i = 0; i < s.length(); i++) {
			if ( s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			else if ( s[i] == ')' || s[i] == ']') {
				char tmp;
				if ( s[i] == ')')
					tmp = '(';
				else
					tmp = '[';
				if ( st.empty()) {
					check = false;
					break;
				}
				char t = st.top();
				if ( t != tmp ) {
					check = false;
					break;
				}
				st.pop();
			}
		}
		if ( !st.empty())
			check = false;
		if ( check )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

