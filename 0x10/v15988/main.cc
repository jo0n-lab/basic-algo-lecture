#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int T;
int n;
long long mod = 1000000009;
long long cache[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    int last = 4;

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    for (int t = 0; t < T; t++) {
        cin >> n;

        for (int i = last; i <= n; i++) {
            cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
            cache[i] %= mod;
        }
        cout << cache[n] << "\n";
        last = max(n, last);
    }
}
