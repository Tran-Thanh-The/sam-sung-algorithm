#include <bits/stdc++.h>
using namespace std;

long long handle( string s, int k) {
	int f[26] = {0};
	for ( int i = 0; i < s.length(); ++i)
		++ f[s[i]-'A'];
	
	priority_queue<int> q;
	for ( int i = 0; i < 26; ++i) {
		if ( f[i] > 0)
			q.push( f[i]);
	}
	
	while( k > 0) {
		int tmp = q.top();
		q.pop();
		-- tmp;
		q.push(tmp);
		-- k;
	}
	
	long long res = 0;
	while( !q.empty()) {
		long long tmp = q.top();
		res += tmp*tmp;
		q.pop();
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
		string s;
		int k;
		cin >> k >> s;
		if ( k > s.length())
			continue;
		cout << handle( s, k) << endl;
	}
	return 0;
}


