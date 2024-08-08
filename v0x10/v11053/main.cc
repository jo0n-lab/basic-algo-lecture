#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__

int N;
int arr[1002];
int cache[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cache[0] = 1;
    for (int i = 1; i < N; i++) {
        cache[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                cache[i] = max(cache[i], 1 + cache[j]);
        }
    }

#ifdef __DEBUG__
    for (int i = 0; i < N; i++)
        cout << cache[i] << " ";
    cout << "\n";
#endif

    cout << *max_element(cache, cache + N);
}
