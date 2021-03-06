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

int main() {

    ll ind = 286, ans;

    for (;;) {
        long double tri = ind * (ind + 1) / 2;
        long double penta = (1 + sqrt(1 + 24 * tri)) / 6.0;
        long double hexa = (1 + sqrt(1 + 8 * tri)) / 4.0;
        if (penta == floor(penta) && hexa == floor(hexa)) {
            ans = tri;
            break;
        }
        ++ind;
    }

	cout << ans;

    return 0;
}

