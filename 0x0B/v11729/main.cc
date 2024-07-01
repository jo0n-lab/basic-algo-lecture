#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define S first
#define D second

int N;
queue<pair<int, int>> Q;
int dir[6] = {0, 0, 0, 3, 2, 1};

void move(int n, int src, int dst) {
    int res = dir[src + dst];
    if (n == 1) {
        Q.push({src, dst});
        return;
    }
    move(n - 1, src, res);
    Q.push({src, dst});
    move(n - 1, res, dst);
}

int main() {
    cin >> N;
    move(N, 1, 3);

    cout << Q.size() << "\n";
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << cur.S << " " << cur.D << "\n";
    }
}
