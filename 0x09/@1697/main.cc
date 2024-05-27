#include <bits/stdc++.h>

using namespace std;

int dist[200002];

int dx[3] = {1, -1, 0};

void print_dist(int N, int K) {
  int len = max(N, K);
  for (int i = 0; i < len; i++) {
    cout << dist[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  // dynamic pr

  int N, K;
  cin >> N >> K;
  if (N == K) {
    cout << 0;
    return 0;
  }

  dist[N] = 0;
  dist[K] = 0;

  queue<int> Q;
  Q.push(N);

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    dx[2] = cur;

    for (int dir = 0; dir < 3; dir++) {
      int nx = cur + dx[dir];

 //     cout << nx << "\n";

      if (nx == K) {
        cout << dist[cur] + 1;
        return 0;
      }
      if (nx < 0 || nx > 200001)
        continue;
      if (dist[nx] > 0)
        continue;

      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }
  // print_dist(N, K);
}
