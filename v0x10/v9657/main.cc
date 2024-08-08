#include <bits/stdc++.h>
using namespace std;

int N;
int cache[1002];
string player[2] = {"SK", "CY"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    cache[1] = 0;
    cache[2] = 1;
    cache[3] = 0;
    cache[4] = 0;

    for (int i = 5; i <= N; i++) {
        int a = !cache[i - 4];
        int b = !cache[i - 3];
        int c = !cache[i - 1];
        cache[i] = a * b * c;
    }

    cout << player[cache[N]];
}
