#include <bits/stdc++.h>
using namespace std;

string BDN() {
	int n;
	cin >> n;
	queue<string> q;
	q.push("1");
	while( true) {
		string result = q.front();
		q.pop();
		
		int surplus = 0;
		for ( int i = 0; i < result.length(); ++i) {
			surplus = (surplus*10 + result[i] - '0')%n;
		} 
		
		if ( surplus == 0)
			return result;
		q.push( result + "0");
		q.push( result + "1");
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		cout << BDN() << endl;
	}
	return 0;
}

