#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

#define X first
#define Y second

int N, M;
int K;
int board[22][22];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int vis[22][22];

void print_config(string s) {
    cout.width(25);
    cout.fill('-');
    cout << s << "\n";
}

void print_board() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout.width(2);
            cout.fill(' ');
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int BFS(pair<int, int> target) {
    if (vis[target.X][target.Y] > 0) {
#ifdef __DEBUG__
        cout << board[target.X][target.Y];
        cout << " is already visited: ";
        cout << vis[target.X][target.Y];
        cout << "\n";
#endif
        return vis[target.X][target.Y];
    }

    int num = board[target.X][target.Y];
    int cnt = 1;

    queue<pair<int, int>> Q;
    stack<pair<int, int>> S;
    vis[target.X][target.Y] = 1;
    Q.push({target.X, target.Y});

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        S.push(cur);
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (board[nx][ny] != num)
                continue;
            if (vis[nx][ny] > 0)
                continue;
            if (nx < 1 || nx > N || ny < 1 || ny > M)
                continue;

            vis[nx][ny] = 1;
            cnt++;
            Q.push({nx, ny});
        }
    }
    int sum = num * cnt;
    while (!S.empty()) {
        pair<int, int> cur = S.top();
        S.pop();
        vis[cur.X][cur.Y] = sum;
    }
    return sum;
}

int dice[3][3] = {{0, 2, 0}, {4, 1, 3}, {0, 5, 0}};

void print_dice() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dice[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_score() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout.width(5);
            cout.fill(' ');
            cout << vis[i][j];
        }
        cout << "\n";
    }
}

pair<int, int> pos;
int which_dir(int prev_dir) {
    int A = 7 - dice[1][1];
    int B = board[pos.X][pos.Y];

    if (A > B)
        return (prev_dir + 1) % 4;
    else if (A < B)
        return (prev_dir + 3) % 4;
    return prev_dir;
}

void move_dice(int dir) {
    int new_dice[3];
    new_dice[1 - dx[dir] - dy[dir]] = 7 - dice[1][1];
    new_dice[1] = dice[1 - dx[dir]][1 - dy[dir]];
    new_dice[1 + dx[dir] + dy[dir]] = dice[1][1];

    pair<int, int> dice_pos = {1 - dx[dir], 1 - dy[dir]};
    for (int i = 0; i < 3; i++) {
        dice[dice_pos.X][dice_pos.Y] = new_dice[dice_pos.X + dice_pos.Y - 1];
        dice_pos.X += dx[dir];
        dice_pos.Y += dy[dir];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

#ifdef __INPUT__
    print_config("INPUT");
    print_board();
#endif

    int ans = 0;
    pos = {1, 1};
    int dir = 0;
    for (int i = 0; i < K; i++) {
        pos.X += dx[dir];
        pos.Y += dy[dir];
        move_dice(dir);
        ans += BFS(pos);
        dir = which_dir(dir);
        int nx = pos.X + dx[dir];
        int ny = pos.Y + dy[dir];
        if (nx < 1 || nx > N || ny < 1 || ny > M)
            dir = (dir + 2) % 4;
#ifdef __DEBUG__
        print_config(to_string(i + 1) + "st case");
        int tmp = board[pos.X][pos.Y];
        board[pos.X][pos.Y] = 0;
        print_board();
        board[pos.X][pos.Y] = tmp;
        print_config("dice");
        print_dice();
        print_config("score");
        print_score();
#endif
    }

#ifdef __DEBUG__
    // print_config("CASE-PRINT");
    // int tmp=
#endif
    cout << ans;
}
