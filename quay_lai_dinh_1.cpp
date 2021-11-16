#include <bits/stdc++.h>
using namespace std;

vector<int> List[1005];
bool ok[1005];
int tr[1005];
map<int, bool> M;

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

vector<int> erase(vector<int> v, int k) {
	vector<int> tmp;
	for( auto i:v) 
		if ( i != k)
			tmp.push_back(i);
	return tmp;
}

int trace( int b, int f) {
	if (!ok[f]) {
		return -1;
	}
	
	vector<int> v;
	while( b != f) {
		v.push_back(f);
		List[f] = erase(List[f], tr[f]);
		List[tr[f]] = erase(List[tr[f]], f);
		f = tr[f];
	}
	v.push_back(b);
	
	int dem = 0;
	for ( auto i:v) {
		if ( !M[i]) {
			dem ++;
			M[i] = true;
		}
	}
	return dem;
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
		M.clear();
		
		int V, E;
		cin >> V >> E;
		
		for ( int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			List[u].push_back(v);
		}
		
		BFS(1, 2);
		int h = trace(1, 2);
		memset(ok, false, sizeof(ok));
		BFS(2, 1);
		int k = trace(2, 1);
		
		if ( h == -1 || k == -1)
			cout << -1 << endl;
		else
			cout << h + k << endl; 
	}
	return 0;
}

