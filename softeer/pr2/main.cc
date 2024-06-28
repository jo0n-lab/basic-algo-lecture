#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

int const_part[6];
int N;
int belt[102];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

// start greater than 1
int traversal(int start) {
    int total = 0;
    int part[6];
    for (int i = 1; i <= 5; i++) {
        total += const_part[i];
        part[i] = const_part[i];
    }

    int i = start;
    int cnt = 0;

    for (; i <= N; i++) {
        if (total == 0)
            return cnt;
        cnt++;
#ifdef __DEBUG__
        cout << cnt << "st pick"
             << "\n";
#endif

        int target = belt[i];
        if (part[target] == 0)
            continue;

        part[target]--;
        total--;
    }

    i = 1;
    for (; i < start; i++) {
        if (total == 0)
            return cnt;
        cnt++;
#ifdef __DEBUG__
        cout << cnt << "st pick"
             << "\n";
#endif

        int target = belt[i];
        if (part[target] == 0)
            continue;

        part[target]--;
        total--;
    }
    return 0x7f7f7f7f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 5; i++)
        cin >> const_part[i];
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> belt[i];

#ifdef __INPUT__
    print_config("INPUT");
    cout << "parts num:\n";
    for (int i = 1; i <= 5; i++)
        cout << const_part[i] << " ";
    cout << "\n\n";
    cout << "belt part:\n";
    for (int i = 1; i <= N; i++)
        cout << belt[i] << " ";
    cout << "\n";
    print_config("");
#endif

    int ans = 0x7f7f7f7f;
    for (int i = 1; i <= N; i++) {
#ifdef __DEBUG__
        print_config("start " + to_string(i));
#endif
        ans = min(ans, traversal(i));
    }
    if (ans == 0x7f7f7f7f)
        cout << -1;
    else
        cout << ans;
}
