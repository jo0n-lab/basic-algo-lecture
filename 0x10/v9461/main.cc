#include <bits/stdc++.h>
using namespace std;

int T, N;
// pre-conds for new triangle
// 1. at least 3 num of tri

long long cache[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int prev = 6;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        // 1: 1 0 0 0 0
        // 2: 1 1 0 0 0
        // 3: 1 1 1 2 0
        // 4: 1 1 1 2 2
        // 5: 1 1 2 2 3
        // 6: 1 2 2 3 4
        // 7: 2 2 3 4 5
        cache[0] = 1;
        cache[1] = 1;
        cache[2] = 1;
        cache[3] = 2;
        cache[4] = 2;
        cache[5] = 3;
        for (int i = prev; i <= N; i++) {
            cache[i] = cache[i - 1] + cache[i - 5];
        }
        cout << cache[N - 1] << "\n";
        prev = max(prev, N);
    }
}
