//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 1000
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

typedef long long ll;

bool isRight(int a, int b, long double c) {
	return c == floor(c) ? true : false;
}

int main() {
	int tp[BIG + 1] = {};
	for (int i = 1; i <= BIG; ++i) {
		for (int j = i; j <= BIG; ++j) {
			long double c = sqrt(i * i + j * j);
			if (isRight(i, j, c) && i + j + (int)c <= BIG) ++tp[i + j + (int)c];
		}
	}
	int mx = 0;
	int ind;
	fl (i, BIG + 1) if (tp[i] > mx) {mx = tp[i]; ind = i;}

	cout << mx << " " << ind;
	
    return 0;
}
