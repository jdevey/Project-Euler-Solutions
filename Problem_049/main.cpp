//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000000007
#define fl(x,m,n) for(int (x) = (m); (x) < (n); ++(x))

using namespace std;

typedef long long ll;
typedef long double lld;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;

    int sqt = sqrt(n);
    
    for (int i = 2; i <= sqt; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPermPair(int a, int b) {
	int digCount1[10] = {}, digCount2[10] = {};
	while (a) {
		++digCount1[a % 10];
		a /= 10;
	}
	while (b) {
		++digCount2[b % 10];
		b /= 10;
	}
	fl (i, 0, 10) if (digCount1[i] != digCount2[i]) return false;
	return true;
}

int main() {

	for (int i = 1001; i < 10000; i += 2) {
		int j = 2;
		while (i + 2 * j < 10000) {
			if (isPrime(i) && isPrime(i + j) && isPrime(i + 2 * j) && isPermPair(i, i + j) && isPermPair(i, i + 2 * j) && i != 1487) cout << i << i + j << i + 2 * j;
			j += 2;
		}
	}
	
    return 0;
}
