#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRINT__
// #define __DEBUG__

int N, M;
int arr[100002];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + N + 1);

#ifdef __INPUT__
    print_config("INPUT");
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
    cout << "\n";
#endif

    int j = 1;
    int i = 1;
    int ans = 0x7fffffff;
    while (i <= N && j <= N) {
        int diff = arr[j] - arr[i];
        if (diff == M) {
            cout << diff;
            return 0;
        } else if (diff > M) {
            i++;
            ans = min(diff, ans);
        } else
            j++;
#ifdef __DEBUG__
        cout << "DEBUG ";
        cout << "i: " << i << " j: " << j;
        cout << " diff: " << diff << " ans: " << ans << "\n";
#endif
    }

    cout << ans;
}
