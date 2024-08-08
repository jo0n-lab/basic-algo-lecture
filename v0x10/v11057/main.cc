#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__

int N;
long long cache[1002][10];
int mod = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    long long ans = 0;

    for (int i = 0; i <= 9; i++)
        cache[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                cache[i][j] += cache[i - 1][k];
            }
            cache[i][j] %= mod;
        }
    }

    for (int i = 0; i <= 9; i++)
        ans += cache[N][i];

#ifdef __DEBUG__
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            cout.width(5);
            cout.fill(' ');
            cout << cache[i][j];
        }
        cout << "\n";
    }
#endif

    cout << ans % mod;
}
