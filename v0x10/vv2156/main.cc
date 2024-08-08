#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int n;
int wine[10002];
int cache1[10002];
int cache2[10002];
int cache3[10002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> wine[i];

    cache1[1] = wine[1];
    cache2[1] = wine[1];
    cache3[1] = wine[1];
    cache1[2] = wine[1] + wine[2];
    cache2[2] = wine[2];
    cache3[2] = wine[2];

    for (int i = 3; i <= n; i++) {
        cache1[i] = max(cache2[i - 1], cache3[i - 1]) + wine[i];
        cache2[i] =
            max({cache1[i - 2], cache2[i - 2], cache3[i - 2]}) + wine[i];
        cache3[i] = cache1[i - 3] + wine[i];
    }

    int max1 = *max_element(cache1 + 1, cache1 + n + 1);
    int max2 = *max_element(cache2 + 1, cache2 + n + 1);
    int max3 = *max_element(cache3 + 1, cache3 + n + 1);

    cout << max({max1, max2, max3});
}
