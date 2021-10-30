#include <bits/stdc++.h>
using namespace std;

long long minPiece() {
	int n;
	cin >> n;
	int x;
	priority_queue< int, vector<int>, greater<int>> q;
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
		x = x1+x2;
		sum += x;
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

	int test;
	cin >> test;
	while( test--) { 
		cout << minPiece() << endl;
	} 
	return 0;
}

