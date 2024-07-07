#include <bits/stdc++.h>
using namespace std;

// TODO: simplification in logic
// 1. check if current case alignes with conditions
// 2. then, another case.
// exp. consider when S given zero

int N, S;
int num[22];

int cnt = 0;

void func(int cur, int tot) {
    if (cur == N) {
        if (tot == S)
            cnt++;
        return;
    }
    func(cur + 1, tot);
    func(cur + 1, tot + num[cur + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    func(0, 0);
    if (S == 0)
        cnt--;
    cout << cnt;
}
