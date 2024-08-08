#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100002];
int target[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> target[i];

    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= M; i++) {
        int t = target[i];
        int st = 1;
        int en = N;

        int mid = (st + en) / 2;
        int ans = 0;
        while (st <= en) {
            if (t == arr[mid]) {
                ans = 1;
                break;
            } else if (t < arr[mid])
                en = mid - 1;
            else
                st = mid + 1;
            mid = (st + en) / 2;
        }
        cout << ans << "\n";
    }
}
