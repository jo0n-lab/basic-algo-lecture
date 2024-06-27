#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int n, m;
long long int card[1000002];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> card[i];

    // tmp & ans: long long int
    // avoid out of range

    for (int i = 0; i < m; i++) {
        int m_idx1 = min_element(card, card + n) - &card[0];
        swap(card[m_idx1], card[0]);
        int m_idx2 = min_element(card + 1, card + n) - &card[0];
        swap(card[m_idx2], card[1]);

        long long int tmp = card[0] + card[1];
        card[0] = tmp;
        card[1] = tmp;
    }

    long long int ans = 0;
    for (int i = 0; i < n; i++)
        ans += card[i];

    cout << ans;
}
