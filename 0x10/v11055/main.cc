#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int N;
int arr[1002];
int cache[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }
    cache[0] = arr[0];

    for (int i = 1; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                tmp = max(tmp, cache[j]);
            }
        }
        cache[i] = arr[i] + tmp;
    }
    cout << *max_element(cache, cache + N);
}
