#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[102][102];
// board 를 0 1 로 설정하여 on/off
int vis[102][102];
stack<pair<int, int>> s[102][102];

void print_board(int N){
	cout<<"\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  board[1][1] = 1;
  //외부 조건 >< 으로

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
	s[x][y].push({a,b});
  }

  int ans = 1;

  queue<pair<int, int>> Q;
  Q.push({1, 1});
  vis[1][1] = 1;

  while (!Q.empty()) {
    pair<int, int> cur;
    cur = Q.front();
    Q.pop();

    //모든 스위치를 킨다.
    //켜지면 큐에 넣어야 하는가?
    //지나왔던 곳과 연결되어 있으면 방문이 가능
    //그러면 일단 꺼져있더라도 큐에 넣어야함
    while (!s[cur.X][cur.Y].empty()) {
      pair<int, int> sw = s[cur.X][cur.Y].top();
      s[cur.X][cur.Y].pop();
      if (board[sw.X][sw.Y])
        continue;
      board[sw.X][sw.Y] = 1;
      ans++;
      if (vis[sw.X][sw.Y]) {
        Q.push({sw.X, sw.Y});
      }
    }

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 1 || nx > N || ny < 1 || ny > N)
        continue;
      if (vis[nx][ny])
        continue;
      //불이 꺼져있더라도 방문 처리 후
      //스위치 켜질 때 다시 큐에 넣어버림
      vis[nx][ny] = 1;
      if (board[nx][ny])
        Q.push({nx, ny});
      //여기서는 불이 켜진 것만 큐에 넣음
    }
  }

 cout << ans;
// print_board(N);

}
