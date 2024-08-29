#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

int N, M;
vector<int> adj[100'002];
int indeg[100'002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        indeg[v]++;
        adj[u].push_back(v);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        int adj_s = adj[cur].size();
        for (int i = 0; i < adj_s; i++) {
            int next = adj[cur][i];
            if (--indeg[next] == 0)
                q.push(next);
        }
    }
}
