#include <bits/stdc++.h>
using namespace std;

vector<int> floo[1005];
bool check[1005];

void BFS( int k) {
	queue<int> q;
	q.push(k);
	while( q.size() > 0) {
		int top = q.front(); 
		q.pop();
		cout << top << " ";
		check[top] = true;
		for ( int i = 0; i < floo[top].size(); i++) {
			if( !check[floo[top][i]]) {
				check[floo[top][i]] = true;
				q.push(floo[top][i]);
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	while( test--) {
		for ( int i = 0; i < 1005; ++i) {
			floo[i].clear();
		}
		memset( check, false, sizeof(check));
		
		int E, V, U;
		cin >> V >> E >> U;
		
		for ( int i = 0 ; i < E; ++i) {
			int u, v;
			cin >> u >> v;
			floo[u].push_back(v);
			floo[v].push_back(u);		
		}
		
		BFS( U);
		cout << endl;

	}
	return 0;
}

