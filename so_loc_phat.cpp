#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
string s;

void Try(int i) {
	if ( i == n)
		return;
	s += "6";
	v.push_back(s);
	Try(i+1);
	s.erase(s.length()-1);
	s += "8";
	v.push_back(s);
	Try(i+1);
	s.erase(s.length()-1);
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

	int test;
	cin >> test;
	while( test--) {
		cin >> n;
		s = "";
		v.clear();
		Try(0);
		sort( v.begin(), v.end(), cmp);
		cout << v.size() << endl;
		for ( int i = v.size()-1; i >= 0; --i)
			cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}

