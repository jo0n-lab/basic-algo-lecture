#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __DEBUG__

int N, M;
vector<int> adj[1002];
queue<int> q;
int vis[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
		adj[v].push_back(u);
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (vis[i] == 1)
            continue;
        q.push(i);
        vis[i] = 1;
        ans++;
#ifdef __DEBUG__
        cout << "DEBUG:: ";
        for (int i = 1; i <= N; i++)
            cout << vis[i];
        cout << "\n";
#endif
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int n_adj = adj[cur].size();
            for (int j = 0; j < n_adj; j++) {
                int v = adj[cur][j];
                if (vis[v] == 1)
                    continue;
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    cout << ans;
}
