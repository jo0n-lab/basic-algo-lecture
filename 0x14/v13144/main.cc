#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int N;
int arr[100'002];
int cache[100'002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    int spos = 1;
    int epos = 1;
    // cache[arr[epos]]=1;
    long long ans = 0;

    for (int spos = 1; spos <= N; spos++) {
        while (epos <= N && cache[arr[epos]] == 0) {
            cache[arr[epos]] = 1;
            epos++;
        }
        cache[arr[spos]] = 0;
        ans += epos - spos;
    }

    cout << ans;
}
