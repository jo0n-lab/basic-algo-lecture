#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRNIT__
// #define __DEBUG__

int N, K;
int arr[10002];

long long step(long long x) {
    long long cur = 0;
    for (int i = 1; i <= K; i++)
        cur += arr[i] / x;
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> N;
    for (int i = 1; i <= K; i++)
        cin >> arr[i];

    long long st = 1;
    long long en = 0x7fffffff;
    long long mid;

    while (st < en) {
        mid = (st + en + 1) / 2;
#ifdef __DEBUG__
        cout << "mid " << mid << " ";
#endif
        long long cur = step(mid);
        if (cur < N)
            en = mid - 1;
        else
            st = mid;
#ifdef __DEBUG__
        cout << "cur " << cur << " ";
        cout << "st " << st << " en " << en << " ";
        cout << "st val " << step(st) << " en val " << step(en) << "\n";
#endif
    }

    cout << st;
}
