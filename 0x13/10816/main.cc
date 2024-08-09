#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int N, M;
int arr[500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> M;

    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= M; i++) {
        int t;
        cin >> t;
        int st = 1;
        int en = N;
        int mid = (st + en) / 2;
        int ans = 0;

        while (st <= en) {
            if (t == arr[mid]) {
                int rpos = mid;
                int lpos = mid - 1;
                while (rpos <= N && arr[rpos] == t) {
                    ans++;
                    rpos++;
                }
                while (lpos >= 1 && arr[lpos] == t) {
                    ans++;
                    lpos--;
                }
                break;
            } else if (t < arr[mid])
                en = mid - 1;
            else
                st = mid + 1;
            mid = (st + en) / 2;
        }
        cout << ans << " ";
    }
}
