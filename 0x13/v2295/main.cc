#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int N;
int U[1002];
vector<int> two;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> U[i];
    sort(U + 1, U + N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            two.push_back(U[i] + U[j]);
        }
    }
    sort(two.begin(), two.end());
    two.erase(unique(two.begin(), two.end()), two.end());

    int ans = 0;
    for (int i = N; i >= 1; i--) {
        int target = U[i];
        for (int j = i - 1; j >= 1; j--) {
            int num = target - U[j];
            if (binary_search(two.begin(), two.end(), num) == 1) {
                ans = target;
                break;
            }
        }
        if (ans != 0)
            break;
    }
    cout << ans;
}
