#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define X first
#define Y second

int V, E;
vector<pair<int, int>> adj[10'002];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
               greater<tuple<int, int, int>>>
    pq;
int vis[10'002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        int cost, u, v;
        cin >> u >> v >> cost;
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }

    vis[1] = 1;
    for (auto p : adj[1])
        pq.push({p.X, 1, p.Y});

    int cnt = 0;
    int ans = 0;
    while (cnt < V - 1) {
        int cost, cur, next;
        tie(cost, cur, next) = pq.top();
        pq.pop();
        if (vis[next] == 1)
            continue;
        vis[next] = 1;
        for (auto p : adj[next]) {
            if (vis[p.Y] == 1)
                continue;
            pq.push({p.X, next, p.Y});
        }
        ans += cost;
        cnt++;
    }

    cout << ans;
}
