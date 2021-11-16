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
		int dau = 0, dem = 0;
		string tmp = "";
		for ( int i = 0; i < s.length(); i++) {
			if (s[i] != ' ' && s[i] != '(' && s[i] != ')' && s[i] != '\t')
				tmp += s[i];
			if ( s[i] == '(' && i > 0) {
				if ( s[i-1] == '-' || ((s[i-1] == ' ' || s[i-1] == '\t') && dau == 1)) {
					dem ++;
					tmp += '(';
				}
				dau = 0;
			}
			if ( s[i] == '-')
				dau = 1;
			if ( s[i] == '+')
				dau = 0;
			
			if ( s[i] == ')' && dem > 0) {
				tmp += ')';
				dem --;
			}
		}
		
		for ( int i = 0; i < tmp.length(); i++) {
			if ( i < tmp.length()-2 && tmp[i] == '(' && tmp[i+2] == ')') {
				tmp[i] = '@';
				tmp[i+2] = '@';
			}
			if ( tmp[i] == '+' && tmp[i+1] == '-')
				tmp[i] = '@';
		}
		for ( int i = 0; i < tmp.length(); i++) {
			if ( tmp[i] != '@')
				cout << tmp[i];
		}
		cout << endl;
	}
	return 0;
}

