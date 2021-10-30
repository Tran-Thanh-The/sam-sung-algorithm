#include <iostream>     
#include <algorithm>    
#include <vector>  

using namespace std;    
 
int main () {
	int a[] = {10,20,30,30,20,10,10,20};
 	int n = 8;
  	sort( a, a+n);               // sorted arr: 10 10 10 20 20 20 30 30
 
//  	std::vector<int>::iterator low,up;
//  	low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  	
  	cout << *lower_bound( a, a+n, 29);
 
  return 0;
}
