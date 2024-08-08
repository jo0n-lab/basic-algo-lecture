#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __DEBUG__
// #define __PRINT__

int n, m;
int board[1002][1002];
int cache[1002][1002];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

void print_board() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_cache() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << cache[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            int input = int(s[j-1]) - int('0');
            board[i][j] = input;
            cache[i][j] = input;
        }
    }

#ifdef __INPUT__
    print_config("INPUT");
    print_board();
#endif

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 0)
                continue;
            cache[i][j] =
                min({cache[i - 1][j - 1], cache[i][j - 1], cache[i - 1][j]}) +
                1;
            ans = max(cache[i][j], ans);
        }
    }

#ifdef __DEBUG__
    print_config("DEBUG");
    print_cache();
#endif
    cout << ans * ans;
}
