#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__

int T, N, M;
int arr[22];

int cache1[10002];
int cache2[10002][22];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        cin >> M;

        // fill_n(&cache2[0][0], 10002 * 22, 0);
        // for (int i = 1; i <= N; i++) {
        //     int num = arr[i];
        //     cache2[0][i] = 1;
        //     for (int j = num; j <= M; j++) {
        //         cache2[j][i] = cache2[j][i - 1] + cache2[j - num][i];
        //     }
        // }

        fill(cache1, cache1 + 10002, 0);
        for (int i = 1; i <= N; i++) {
            int num = arr[i];
            cache1[0] = 1;
            for (int j = num; j <= M; j++) {
                cache1[j] += cache1[j - num];
            }
        }

        // cout << cache2[M][N] << "\n";
        cout << cache1[M] << "\n";
    }
}
