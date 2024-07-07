#include <bits/stdc++.h>
using namespace std;

int N;
long long num[100002];
pair<long long, int> cnt[100002];

bool compare(pair<long long, int> &a, pair<long long, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num, num + N);

    int pos = 0;
    cnt[0] = {num[0], 0};
    for (int i = 0; i < N; i++) {
        if (cnt[pos].first != num[i])
            cnt[++pos] = {num[i], 1};
        else
            cnt[pos].second++;
    }

    sort(cnt, cnt + N, compare);
    cout << cnt[0].first;
}
