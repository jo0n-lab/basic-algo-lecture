#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define X first
#define Y second

int N, M;
char board[12][12];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
// for(int dir=0;dir<4;dir++)
// 0:down | 1:up | 2:right | 3:left

pair<int, int> red;
pair<int, int> blue;
pair<int, int> ext;

int dist[12][12][12][12];
queue<pair<int, int>> Qr;
queue<pair<int, int>> Qb;

vector <pair<pair<int,int>,pair<int,int>>> print_V;

void print_config(string s) {
    cout.width(25);
    cout.fill('-');
    cout << s << "\n";
}

void print_board() {
    print_config("BOARD");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout.width(2);
            cout.fill(' ');
            cout << board[i][j];
        }
        cout << "\n";
    }
}

bool is_red_first(int dir) {
    // 0:down | 1:up | 2:right | 3:left
    if (dir == 0 && red.Y == blue.Y) { // down
        if (red.X > blue.X)
            return true;
        // | blue |
        // | red  |
        else
            return false;
        // | red  |
        // | blue |
    } else if (dir == 1 && red.Y == blue.Y) { // up
        if (red.X < blue.X)
            return true;
        else
            return false;
    } else if (dir == 2 && red.X == blue.X) { // right
        if (red.Y > blue.Y)
            return true;
        else
            return false;
    } else if (dir == 3 && red.X == blue.X) { // left
        if (red.Y < blue.Y)
            return true;
        else
            return false;
    }
    return true;
}

pair<int, int> cur_r;
pair<int, int> cur_b;
pair<int, int> move(int dir, bool is_red) {
    int dX = dx[dir];
    int dY = dy[dir];
    pair<int, int> target;
    pair<int, int> evade;

    if (is_red == true) {
        target = red;
        evade = cur_b;
    } else {
        target = blue;
        evade = cur_r;
    }
    int nx = target.X;
    int ny = target.Y;
    while (1) {
        if (nx + dX < 0 || nx + dX >= N || ny + dY < 0 || ny + dY >= M)
            break;
        if (nx + dX == ext.X && ny + dY == ext.Y)
            return {11, 11};
        // return {nx + dX, ny + dY};
        if (board[nx + dX][ny + dY] == '#')
            break;
        if (nx + dX == evade.X && ny + dY == evade.Y)
            break;
        nx += dX;
        ny += dY;
    }
    return {nx, ny};
}

// pair<int, int> cur_r;
// pair<int, int> cur_b;
void step(int dir) {
    bool red_first = is_red_first(dir);
    if (red_first == true) {
        cur_r = move(dir, true);
        cur_b = move(dir, false);
    } else {
        cur_b = move(dir, false);
        cur_r = move(dir, true);
    }
    if (dist[cur_r.X][cur_r.Y][cur_b.X][cur_b.Y] >= 0)
        return;
    dist[cur_r.X][cur_r.Y][cur_b.X][cur_b.Y] =
        dist[red.X][red.Y][blue.X][blue.Y] + 1;
    Qr.push(cur_r);
    Qb.push(cur_b);
}

void BFS() {
    fill_n(&dist[0][0][0][0], 12 * 12 * 12 * 12, -1);
    dist[red.X][red.Y][blue.X][blue.Y] = 0;

    Qr.push(red);
    Qb.push(blue);

    while (!Qr.empty()) {
        red = Qr.front();
        Qr.pop();
        blue = Qb.front();
        Qb.pop();

        if (dist[red.X][red.Y][blue.X][blue.Y] > 10)
            continue;
        if (blue.X == 11 && blue.Y == 11)
            continue;
        if (red.X == 11 && red.Y == 11) {
            cout << dist[red.X][red.Y][blue.X][blue.Y];
#ifdef __DEBUG__
			cout<<"\n";
			cout<<"red "<<red.X<<" "<<red.Y<<"\n";
			cout<<"blue "<<blue.X<<" "<<blue.Y<<"\n";
#endif
            return;
        }
        for (int dir = 0; dir < 4; dir++)
            step(dir);
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char input;
            cin >> input;
            board[i][j] = input;
            if (input == 'R')
                red = {i, j};
            else if (input == 'B')
                blue = {i, j};
            else if (input == 'O')
                ext = {i, j};
            // else if(input=='O') ext={i,j};
        }
    }

#ifdef __INPUT__
    print_board();
#endif

#ifdef __PRINT__
    print_config("ANSWER");
#endif
    BFS();
}
