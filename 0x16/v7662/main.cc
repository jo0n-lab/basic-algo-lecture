#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        multiset<int> s;
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            char comm;
            cin >> comm;
            int n;
            cin >> n;

            if (comm == 'I')
                s.insert(n);
            else {
                if (s.empty())
                    continue;
                if (n == 1)
                    s.erase(prev(s.end()));
                else
                    s.erase(s.begin());
            }
        }
        if (s.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(s.end()) << " " << *s.begin() << "\n";
    }
}
