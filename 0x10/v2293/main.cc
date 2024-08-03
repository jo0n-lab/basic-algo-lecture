#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__

int n, k;
int arr[102];
int cache[10002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    cache[0] = 1;
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        for (int j = num; j <= k; j++) {
            cache[j] += cache[j - num];
        }
    }

#ifdef __DEBUG__
    cout << "DEBUG\n";
    for (int i = 1; i <= k; i++) {
        cout << cache[i] << "\n";
    }
    cout << "\n";
#endif

    cout << cache[k];
}
