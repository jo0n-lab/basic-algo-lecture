#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRINT__
// #define __DEBUG__

int N, M;
int arr[10'002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

#ifdef __INPUT__
    cout << "INPUT:: ";
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
    cout << "\n";
#endif

    int spos = 1;
    int epos = 1;
    int tmp = 0;
    int ans = 0;
    while (spos <= N && epos <= N) {
        if (tmp >= M) {
            if (tmp == M)
                ans++;
            tmp -= arr[spos++];
        } else
            tmp += arr[epos++];
    }
    for (; spos <= N; spos++) {
        if (tmp < M)
            break;
        if (tmp == M)
            ans++;
        tmp -= arr[spos];
    }
    cout << ans;
}
