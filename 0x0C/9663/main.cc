#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

#define X first
#define Y second

int N;
int vis[17][17];
pair<int, int> Qpos[17];
int ans = 0;

void print_config(string s) {
    cout.width(25);
    cout.fill('-');
    cout << s << "\n";
}

void print_case(int k) {
    print_config(to_string(ans) + "st case " + to_string(k) + "st queen");
    int board[17][17];
    fill_n(&board[0][0], 17 * 17, 0);
    for (int i = 1; i <= k; i++) {
        pair<int, int> pos = Qpos[i];
        board[pos.X][pos.Y] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool is_possible(int x, int y, int k) {
    if (k == 0)
        return true;
    for (int i = 1; i <= k; i++) {
        pair<int, int> target = Qpos[i];
        if (abs(target.X - x) == abs(target.Y - y)) {
#ifdef __DEBUG__
            cout << "passing " << x << " " << y << "\n";
#endif
            return false;
        }
        if (target.X - x == 0 || target.Y - y == 0) {
#ifdef __DEBUG__
            cout << "passing " << x << " " << y << "\n";
#endif
            return false;
        }
    }
    return true;
}

void func(int k, int x, int y) {
    if (k > N) {
        ans++;
#ifdef __DEBUG__
        print_case(N);
#endif
        return;
    } else {
        for (int i = x; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (vis[i][j] == 0) {
                    if (is_possible(i, j, k - 1) == true) {
                        Qpos[k] = {i, j};
#ifdef __DEBUG__
                        print_case(k);
#endif
                        vis[i][j] = 1;
                        func(k + 1, i+1, j);
                        vis[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    func(1, 0, 0);
    cout << ans;
}
