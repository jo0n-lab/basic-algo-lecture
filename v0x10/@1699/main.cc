#include <bits/stdc++.h>
using namespace std;

//#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N;
int cache[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    long long tmp = 1;
    for (int i = 1; i <= N; i++) {
        if ((tmp + 1) * (tmp + 1) <= i)
            tmp++;
        cache[i] = tmp * tmp;
    }

#ifdef __DEBUG__
    for (int i = 1; i <= N; i++)
        cout << cache[i] << "\n";
#endif

    int ans = 0;
    while (N > 0) {
        ans++;
        N -= cache[N];
    }

    cout << ans;
}
