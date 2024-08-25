#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pos_pq;
// min heap
priority_queue<int, vector<int>, greater<int>> neg_pq;
// min heap

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        if (input == 0) {
            if (!pos_pq.empty() && !neg_pq.empty()) {
                if (pos_pq.top() >= neg_pq.top()) {
                    cout << -neg_pq.top() << "\n";
                    neg_pq.pop();
                } else if (pos_pq.top() < neg_pq.top()) {
                    cout << pos_pq.top() << "\n";
                    pos_pq.pop();
                }
            } else if (!pos_pq.empty()) {
                cout << pos_pq.top() << "\n";
                pos_pq.pop();
            } else if (!neg_pq.empty()) {
                cout << -neg_pq.top() << "\n";
                neg_pq.pop();
            } else
                cout << 0 << "\n";
        } else {
            if (input < 0)
                neg_pq.push(abs(input));
            else
                pos_pq.push(input);
        }
    }
}
