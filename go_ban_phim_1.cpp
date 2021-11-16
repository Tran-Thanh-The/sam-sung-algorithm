#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	
	stack<char> a, b;
	
	for ( int i = 0; i < s.length(); i++) {
		if ( s[i] == '<') {
			if ( !a.empty()) {
				b.push(a.top());
				a.pop();
			}
		}
		else if ( s[i] == '>' ) {
			if ( !b.empty()) {	
				a.push(b.top());
				b.pop();
			}
		}
		else if ( s[i] == '-') {
			if ( !a.empty())
				a.pop();
		}
		else {
			a.push(s[i]);
		}
	}
	
	string res = "";
	while( !a.empty()) {
		res = a.top() + res;
		a.pop();
	}
	
	while( !b.empty()) {
		res += b.top();
		b.pop();
	}
	
	cout << res;
	
	return 0;
}

