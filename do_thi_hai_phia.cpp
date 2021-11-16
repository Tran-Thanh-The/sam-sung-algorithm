#include <bits/stdc++.h>
using namespace std;

vector<int> List[1005];
bool ok[1005];
bool res;
int c[1005];

void BFS(int i) {
	queue<int> q;
	q.push(i);
	c[i] = 1;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		int tmp = 1;
		if ( c[t] != 2)
			tmp = 2;
		for ( auto j:List[t]) {
			if ( c[t] == c[j]) {
				res = false;
				return;
			}
			if ( c[j] == 0) {
				c[j] = tmp;
				q.push(j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	while( test--) {
		res = true;
		memset(c, 0, sizeof(c));
		for ( int i = 0; i < 1005; i++)
			List[i].clear();
		
		int V, E;
		cin >> V >> E;
		
		for ( int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			List[u].push_back(v);
			List[v].push_back(u);
		}
		
		BFS(1);

		if (res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

