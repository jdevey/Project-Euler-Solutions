//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000000007
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

typedef long long ll;

bool isPenta(long double n) {
	if (n < 1) return false;
	long double root = (1 + sqrt(24.0 * n + 1)) / 6;
	return root - floor(root) == 0.0;
}

ll genPenta(ll n) {
	return n * (3 * n - 1) / 2;
}

int main() {
	
	int stop = 10000;
 	ll bestOne, bestTwo;
	ll minDiff = 0x7fffffffffffffff;
	for (int i = 1; i < stop; ++i) {
		ll penta1 = genPenta(i);
		for (int j = 1; j <= i; ++j) {
			ll penta2 = genPenta(j);
			ll diff = penta1 - penta2;
			//cout << diff << " " << penta1 + penta2 << endl;
			//if (isPenta((long double)diff) && isPenta((long double)(penta1 + penta2))) cout << "match" << endl;
			if (isPenta((long double)diff) && isPenta((long double)(penta1 + penta2)) && diff < minDiff) {minDiff = diff, bestOne = penta1, bestTwo = penta2;}
		}
	}

	cout << minDiff << endl;
	
    return 0;
}
