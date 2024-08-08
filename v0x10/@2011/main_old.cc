#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

string alpha = "abcdefghijklmnopqrstuvwxyz";
int alpha_len = 26;
int n;
int arr[5002];
int cache[5002];
int mod = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    n = s.length();

    for (int i = 1; i <= n; i++)
        arr[i] = int(s[i - 1]) - int('0');

#ifdef __INPUT__
    cout << "INPUT\n";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
#endif

    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;
    for (int i = 3; i <= n; i++)
        cache[i] = (cache[i - 1] + cache[i - 2]) % mod;

    long long subs = 0;
    if (arr[1] == 0) {
        cout << 0;
        return 0;
    } else if (arr[n] == 0) {
        subs += cache[0];
    }
    for (int i = 1; i <= n - 1; i++) {
        int target = arr[i] * 10 + arr[i + 1];
        if (target <= 0) {
            cout << 0;
            return 0;
        }
        if (arr[i] == 0)
            subs += cache[n - i];
        else if (target > 26)
            subs += cache[n - (i + 1)];
#ifdef __DEBUG__
        cout << "target: " << target << "\n";
        cout << "cur sub: " << subs << "\n";
#endif
    }
    subs %= mod;

    int ans = (cache[n] + mod - subs) % mod;

    cout << ans;
}
