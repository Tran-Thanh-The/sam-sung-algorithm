#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
string s;

void Try( int i) {
	if ( i == 13)
		return;
	s += "4";
	v.push_back(s);
	Try(i+1);
	s.erase(s.length()-1);
	s += "5";
	v.push_back(s);
	Try(i+1);
	s.erase(s.length()-1);
}

string Reverse( string s) {
	string res = "";
	for ( int i  = s.length()-1; i >= 0; i--) {
		res += s[i];
	}
	return res;
}

bool cmp( string a, string b) {
	if ( a.length() != b.length())
		return a.length() < b.length();
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	s = "";
	Try(0);
	sort( v.begin(), v.end(), cmp);
	
	int test;
	cin >> test;
	while( test--) {
		cin >> n;
		for ( int i = 0; i < n; i++)
			cout << v[i] << Reverse(v[i]) << " ";
		cout << endl;
	}
	return 0;
}

