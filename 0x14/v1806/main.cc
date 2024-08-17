#include <bits/stdc++.h>
using namespace std;

//#define __INPUT__
//#define __PRINT__
//#define __DEBUG__

int N, S;
int arr[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
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
    int tmp = arr[epos];
    int ans = 0x7fffffff;

    // always spos<=epos
    while (spos <= N && epos <= N) {
        // either of one as N+1
#ifdef __DEBUG__
        if (spos > epos) {
            cout << "DEBUG:: ";
            cout << "out of bounds, ";
            cout << "spos: " << spos << " epos: " << epos << "\n";
        }
#endif
        if (tmp < S)
            tmp += arr[++epos];
        else {
            ans = min(ans, epos - spos + 1);
            tmp -= arr[spos++];
        }
    } // consider state after break
    for (; spos <= N; spos++) {
        if (tmp < S)
            break;
        ans = min(ans, N - spos + 1);
        tmp -= arr[spos];
    }

    if (ans == 0x7fffffff)
        ans = 0;
    cout << ans;
}
