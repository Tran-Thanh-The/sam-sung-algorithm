#include <bits/stdc++.h>
using namespace std;

vector<int> floo[1005];
bool check[1005];
int tr[1005];

void BFS( int u, int v) {
	queue<int> q;
	q.push( u);
	while ( q.size() > 0) {
		int top = q.front();
		q.pop();
		check[top] = true;
		if ( top == v)
			return;
		for ( int i = 0; i < floo[top].size(); i++) {
			if ( !check[floo[top][i]]) {
				tr[floo[top][i]] = top;
				q.push(floo[top][i]);
				check[floo[top][i]] = true;
			}
		}
	}
}

bool trace( int u, int v) {
	if ( !check[v]) {
		return false;
	}
	while( u != v) {
		if ( v == 0) {
			return false;
		}
		v = tr[v];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int test;
	cin >> test;
	while( test--) {	
		for ( int i = 0; i < 1005; ++i) {
			floo[i].clear();
		}
		memset( check, false, sizeof(check));
		memset( tr, 0, sizeof(tr));
		
		int E, V, B, F;
		cin >> V >> E;
		
		for ( int i = 0 ; i < E; ++i) {
			int u, v;
			cin >> u >> v;
			floo[u].push_back(v);
			floo[v].push_back(u);		
		}
		int k;
		cin >> k;
		while ( k--) {
			int b, f;
			cin >> b >> f;
			memset( check, false, sizeof(check));
			memset( tr, 0, sizeof(tr));
			BFS( b, f);
			if ( trace( b, f)) 
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}


