#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

long long minPiece() {
	int n;
	cin >> n;
	int x;
	priority_queue< long long, vector<long long>, greater<long long>> q;
	while( n--) {
		cin >> x;
		q.push(x);
	}
		
	long long sum = 0;
	int x1, x2;
	while ( true) {
		x1 = q.top(); 
		q.pop();
		x2 = q.top();
		q.pop();
		x = (x1+x2)%mod;
		sum = (sum + x)%mod;
		if ( q.empty())
			return sum;
		q.push(x);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while ( t--)
		cout << minPiece() << endl;
	return 0;
}

