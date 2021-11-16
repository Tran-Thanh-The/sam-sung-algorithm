#include <bits/stdc++.h>
using namespace std;

vector<int> List[1005];
bool ok[1005];
int tr[1005];

void BFS( int b, int f) {
	queue<int> q;
	q.push(b);
	ok[b] = true;
	while( !q.empty()) {
		int t = q.front();
		q.pop();
		ok[t] = true;
		if ( t == f)
			return;
		for ( auto i:List[t]) {
			if (!ok[i]) {
				q.push(i);
				tr[i] = t;
				ok[i] = true;
			}
		}
	}
}

void trace( int b, int f) {
	if (!ok[f]) {
		cout << -1 << endl;
		return;
	}
	vector<int> v;
	while( b != f) {
		v.push_back(f);
		f = tr[f];
	}
	v.push_back(b);
	
	for ( int i = v.size()-1; i >= 1; i--)
		cout << v[i] << " -> ";
	cout << v[0];
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		for ( int i = 0; i < 1005; i++)
			List[i].clear();
		memset(ok, false, sizeof(ok));
		memset(tr, 0, sizeof(tr));
		
		int V, E, B, F;
		cin >> V >> E >> B >> F;
		
		for ( int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			List[u].push_back(v);
		}
		
		BFS(B, F);
		trace(B, F);
	}
	return 0;
}

