#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__

int N;
int arr[20][2];
int cache[20][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i][0] >> arr[i][1];

#ifdef __INPUT__
    cout << "INPUT\n";
    for (int i = 1; i <= N; i++)
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    cout << "\n";
#endif

    cache[1][0] = arr[1][0] + 1 - 1;
    cache[1][1] = arr[1][1];
    for (int i = 2; i <= N; i++) {
        int tmp[2] = {0, 0};
        for (int j = 1; j < i; j++) {
            if (cache[j][0] < i && tmp[1] < cache[j][1]) {
                tmp[0] = cache[j][0];
                tmp[1] = cache[j][1];
            }
        }
        cache[i][0] = arr[i][0] + i - 1;
        cache[i][1] += tmp[1] + arr[i][1];
    }

#ifdef __DEBUG__
    cout << "\n";
    for (int i = 1; i <= N; i++)
        cout << cache[i][0] << " " << cache[i][1] << "\n";
    cout << "\n";
#endif

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (ans < cache[i][1] && cache[i][0] <= N)
            ans = cache[i][1];
    }
    cout << ans;
}
