#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }

    int ans = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }

    cout << ans;

#ifdef __DEBUG__
    cout << "\nDEBUG:: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
#endif
}
