#include <bits/stdc++.h>
using namespace std;
#define p pair<int, int>

vector<int> List[1005];
vector<pair<int, int>> res;
bool ok[1005];

void BFS(int u) {
	queue<int> q;
	q.push(u);
	while( !q.empty()) {
		int t = q.front();
		q.pop();
		ok[t] = true;
		for ( auto i:List[t]) {
			if ( !ok[i]) {
				ok[i] = true;
				res.push_back(p(t, i));
				q.push(i);
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
		for ( int i = 0; i < 1005; i++)
			List[i].clear();
		res.clear();
		memset(ok, false, sizeof(ok));
		
		int N, E, U;
		cin >> N >> E >> U;
		
		for ( int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			List[u].push_back(v);
			List[v].push_back(u);
		}
		
		BFS(U);
		
		if ( res.size() != N-1)
			cout << -1 << endl;
		else
			for ( auto i:res)
				cout << i.first << " " << i.second << endl;
	}
	return 0;
}

