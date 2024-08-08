#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int n;
long long cache[32];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n % 2) {
        cout << 0;
        return 0;
    }

    cache[0] = 1;
    cache[2] = 3;
    int uniq = 2;
    for (int i = 4; i <= n; i += 2) {
        cache[i] = cache[i - 2] * cache[2];
        for (int j = 4; j <= i; j += 2) {
            cache[i] += cache[i - j] * uniq;
        }
    }

    cout << cache[n];
}
