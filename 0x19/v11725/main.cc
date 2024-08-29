#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __DEBUG__

int N;
vector<int> adj[100'002];
int parent[100'002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int adj_s = adj[cur].size();
        for (int i = 0; i < adj_s; i++) {
            int next = adj[cur][i];
            if (parent[cur] == next)
                continue;
            parent[next] = cur;
            q.push(next);
#ifdef __DEBUG__
            cout << "DEBUG:: " << cur << " " << next << "\n";
#endif
        }
    }

    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";
}
