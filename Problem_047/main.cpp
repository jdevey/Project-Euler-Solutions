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

//The first part of the pair is the prime factor; the second part is its frequency
//Efficiency can probably be vastly improved by considering square roots
//Includes the number itself in the list but not 1
vector <pair <int, int>> makePrimeFactors(ll n) {
    vector <pair <int, int>> pf;
    int start = 2;
    while (true) {
        if (n % start == 0) {
            if (!pf.empty() && pf.back().first == start) ++pf.back().second;
            else pf.emplace_back(make_pair(start, 1));
            n /= start;
        }
        else ++start;
        if (start > n) break;
    }
    return pf;
}

int main() {

    int ind = 644;

    vector <vector <pair <int, int>>> fac (4, vector <pair <int, int>> (0, make_pair(0, 0)));
    fl (i, 0, 4) fac[i] = makePrimeFactors(ind + i);

    while (true) {
        bool good = true;
		fl (i, 0, 4) if (fac[i].size() != 4) good = false;
        fl (i, 0, 3) {
            fl (j, 0, fac[i].size()) {
                fl (k, i + 1, 4) {
                    fl (m, 0, fac[k].size()) {
                        if (fac[i][j].first == fac[k][m].first && fac[i][j].second == fac[k][m].second) good = false;
                    }
                }
            }
        }
        if (good) break;
        fl (i, 0, 3) fac[i] = fac[i + 1];
        ++ind;
        fac[3] = makePrimeFactors(ind + 3);
    }

    cout << ind;

    return 0;
}


