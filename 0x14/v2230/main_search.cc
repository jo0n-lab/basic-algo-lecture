#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRINT__
// #define __DEBUG__

int N, M;
int arr[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + N + 1);
#ifdef __INPUT__
    cout << "INPUT\n";
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
    cout << "\n";
#endif

    int ans = 0x7fffffff;
    for (int i = 1; i <= N; i++) {
        int target = arr[i] - M;
        int j = upper_bound(arr + 1, arr + i, target) - arr - 1;
#ifdef __DEBUG__
        cout << "DEBUG ";
        cout << "target: " << target << " " << arr[j] << " ";
        cout << "target idx: " << j << "\n";
#endif
        if (arr[j] <= target && j > 0)
            ans = min(ans, arr[i] - arr[j]);
    }

    cout << ans;
}
