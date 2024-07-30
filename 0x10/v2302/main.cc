#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int N, M;
int arr[42];
long long cache[42];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> arr[i];
    arr[M + 1] = N + 1;

    cache[1] = 1;
    cache[2] = 2;
    for (int i = 3; i <= N; i++)
        cache[i] = cache[i - 1] + cache[i - 2];

    long long ans = 1;

    for (int i = 1; i <= M + 1; i++) {
        int target = cache[arr[i] - arr[i - 1] - 1];
        if (target == 0)
            continue;
        ans *= target;
    }

    cout << ans;
}
