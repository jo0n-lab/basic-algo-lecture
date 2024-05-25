#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int vis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  fill_n(&board[0][0], 102 * 102, -1);

  int N, M;
  cin >> M >> N;
  int num = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == -1)
        num++;
    }
  }

  int total_num = N * M - num;

  queue<pair<int, int>> Q;
  Q.push({0, 0});
  vis[0][0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      pair<int, int> cur = Q.front();Q.pop();
	  
	  while
