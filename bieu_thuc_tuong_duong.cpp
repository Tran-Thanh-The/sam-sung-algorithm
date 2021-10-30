#include <bits/stdc++.h>
using namespace std;

string equivalent( string s) {
	int dau = 0;
	string n = "0";
	string res = "";
	
	for ( int i = 0; i < s.length(); i++) {
		if ( s[i] >= 97 && s[i] <= 122) {
			if ( i != 0 && s[i-1] == '(')
				dau = 0;
			if ( (dau+n[n.length()-1])%2 == 0) {
				res += "+";
				res += s[i];
			} else {
				res += "-";
				res += s[i];
			}
		} else {
			if ( s[i] == '(') {
				if ( i != 0 && s[i-1] == '(') {
					n += n[n.length()-1];
				} else {
					if ( dau%2 == 0) { 
						if ( n[n.length()-1] == '0')
							n += "0";
						else
							n += "1";
					} else {
						if ( n[n.length()-1] == '0')
							n += "1";
						else
							n += "0";
					}
				}
			} else if ( s[i] == '+') {
				dau = 0;
			} else if ( s[i] == '-') {
					dau = 1;
			} else {
				n.pop_back();
			}
		}
 	}
 	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		string a, b;
		cin >> a >> b;
		if ( equivalent( a) == equivalent( b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

