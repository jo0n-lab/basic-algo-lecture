#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int N;
vector<int> v;
vector<int> uniq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    uniq = v;
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()),uniq.end());

    for (auto i = 0; i < v.size(); i++) {
        cout << lower_bound(uniq.begin(), uniq.end(), v[i]) - uniq.begin()
             << " ";
    }
}
