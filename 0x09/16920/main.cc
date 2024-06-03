#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[8] = { 1, -1, 1, -1};
int dy[8] = { 1, 1, -1, -1};
char board[1002][1002];
//성 생기면 vis=1
int vis[102][102];

//플레이어 초기위치 스택형 배열
stack<pair<int, int>> arr[10];

//플레이어 거리 배열
int S[10];

//플레이어 정답
int ans[10];

void print_board(int N, int M) {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    //자료구조 선택
    // s1~sn 플레이어들이 순번을 거쳐 BFS 를 돌음
    //각 턴이 끝날때는 본인의 큐에 새롭게 생성된 영역을 넣음
    //따라서 큐 배열
    //
    //하지만 생각해보면 큐가 선입선출이기 때문에 하나만 있어도
    //순서대로 턴제 플레이 가능.
    //따라서 위치만 저장할 플레이어 배열만 필요
    //
    //
    // exc: 초기 성의 위치가 여러개일 수 있음
    //따라서 초기위치를 정수형 배열은 적절하지 않음
    //스택이나 큐같은 동적 배열이 효과적임

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, P;
    cin >> N >> M >> P;

    //플레이어 거리 입력
    for (int i = 1; i <= P; i++)
        cin >> S[i];

    //보드 모양 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            int num = int(c) - int('0');

            board[i][j] = c;
            if (num > 0 && num < 10)
                arr[num].push({i, j});
        }
    }

    //플레이어 초기위치 큐 넣기
    queue<tuple<int, int, int>> Q;
    for (int i = 1; i <= P; i++) {
        while (!arr[i].empty()) {
            pair<int, int> tmp = arr[i].top();
            arr[i].pop();

            //정답 초기화
            ans[i]++;

            Q.push({tmp.X, tmp.Y, i});
        }
    }

    // BFS
    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        int curX, curY, curN;
        tie(curX, curY, curN) = cur;
        vis[curX][curY] = curN;

        for (int l = 0; l <= S[curN]; l++) {
			int a=l;
			int b=S[curN]-a;



            for (int dir = 0; dir < 4; dir++) {
			for(int i=0;i<a;i++){
				for(int j=0;j<b;j++){
                int nx = curX + dx[dir] * a;
                int ny = curY + dy[dir] * b;

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                if (vis[nx][ny] || board[nx][ny] != '.')
                    continue;

                vis[nx][ny] = curN;
                ans[curN]++;
                Q.push({nx, ny, curN});
            }
        }
    }
    for (int i = 1; i <= P; i++)
        cout << ans[i] << " ";
    print_board(N, M);
}
