#include <bits/stdc++.h>
using namespace std;

//#define __DEBUG__
//#define __INPUT__
//#define __PRINT__

int N;
int cache[1000001];

void print_config(string s) {
    cout.width(15);
    cout.fill('-');
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
#ifdef __INPUT__
    print_config("input");
    cout << N << "\n";
#endif

    cache[1] = 0;
    for (int i = 2; i <= N; i++) {
        cache[i] = cache[i - 1] + 1;
        if (i % 2 == 0)
            cache[i] = min(cache[i / 2] + 1, cache[i]);
        if (i % 3 == 0)
            cache[i] = min(cache[i / 3] + 1, cache[i]);
    }

    cout << cache[N];
}
