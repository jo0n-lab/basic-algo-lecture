#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRINT__
// #define __DEBUG__

int N, M;
int arr[100002];
long long cache[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++)
        cache[i] = cache[i - 1] + arr[i];

#ifdef __DEBUG__
    cout << "DEBUG\n";
    for (int i = 1; i <= N; i++) {
        cout << cache[i] << "\n";
    }
    cout << "\n";
#endif

    for (int k = 1; k <= M; k++) {
        int i, j;
        cin >> i >> j;
        cout << cache[j] - cache[i - 1] << "\n";
    }
}
