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

void sieveOfEratosthenes(bool sieve[], int sz) {
	sieve[0] = true, sieve[1] = true;
	int sqt = sqrt(sz);
	fl (i, 2, sqt) {
		int ind = 2 * i;
		if (!isPrime(i)) sieve[i] = true;
		while (ind < sz) {
			sieve[ind] = true;
			ind += i;
		}
	}
}

int main() {
	
	int sz = 1000000, sqt = sqrt(sz);
	bool sieve[sz] = {};

	sieveOfEratosthenes(sieve, sz);

	bool ansSieve[sz] = {};

	fl (i, 2, sz) {
		if (sieve[i]) continue;
		fl (j, 1, sqt) {
			ll sum = i + 2 * j * j;
			if (sum < sz) ansSieve[sum] = true;
		}
	}

	ll ans = -1;
	fl (i, 9, sz) { //9 is the smallest odd composite prime
		if (!ansSieve[i] && sieve[i] && i & 1) {
			ans = i;
			break;
		}
	}
	
	cout << ans;
	
    return 0;
}
