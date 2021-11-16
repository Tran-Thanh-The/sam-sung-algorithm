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
		string s;
		getline(cin, s);
		stack<int> a;
		int d = 1;
		
		for ( int i = 0; i < s.length(); ++i) {
			if ( s[i] == '(') {
				a.push(d);
				cout << d << " ";
				d ++;
			}
			else if ( s[i] == ')') {
				cout << a.top() << " ";
				a.pop();
			}
		}
		cout << endl;
	}
	return 0;
}

