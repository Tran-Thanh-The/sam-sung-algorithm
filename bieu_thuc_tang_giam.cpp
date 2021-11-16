#include <bits/stdc++.h>
using namespace std;

void solve(string seq, int n) {
    string result;
    stack<int> st;
    for (int i = 0; i <= seq.length(); i++) {
        st.push(i + 1);
        if (i == seq.length() || seq[i] == 'I') {
            while (!st.empty()) { 
                result += to_string(st.top());
                st.pop();
            }
        }
    }
 	cout << "Test " << n << ": ";
    cout << result << endl;
}

int main() {
	int test;
	cin >> test;
	int t = 1;
	while( test--) {
		string s;
		cin >> s;
		solve(s, t);
		t ++;
	}
	return 0;
}

