#include <bits/stdc++.h>
using namespace std;

int main() {

	
	ifstream ifp;
		
	ifp.open("A.txt");
	string s;
	ifp >> s;
	cout << "this is the first line of the file PTIT.in: " << s << endl;
	ofstream ofp;
	ofp.open("PTIT.out");
		
//	while( !ifp.eof() ) {
//		string s;
//		getline( ifp, s);
		ofp << s;
//	}
		
	ofp.close();
	ifp.close();

	return 0;
}

