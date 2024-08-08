#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N;
long long cache[1000002];
int mod = 15746;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    cache[1] = 1;
    cache[2] = 2;
    // 100 001 111
    // 0000 0011 1001 1100 1111
    for (int i = 3; i <= N; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % mod;
    }

    cout << cache[N];
}
