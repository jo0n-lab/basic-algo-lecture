#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

int N, M, V;
vector<int> adj[1002];
int vis[1002];

void DFS(int cur) {
    vis[cur] = 1;
    cout << cur << " ";
    int adj_s = adj[cur].size();
    for (int i = 0; i < adj_s; i++) {
        int next = adj[cur][i];
        if (vis[next] == 1)
            continue;
        DFS(next);
    }
    return;
}

void BFS() {
    fill(vis, vis + N + 1, 0);
    queue<int> q;
    vis[V] = 1;
    q.push(V);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        int adj_s = adj[cur].size();
        for (int i = 0; i < adj_s; i++) {
            int next = adj[cur][i];
            if (vis[next] == 1)
                continue;
            vis[next] = 1;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());

    DFS(V);
    cout << "\n";
    BFS();
}
