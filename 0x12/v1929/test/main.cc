
#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
// #define __INPUT__
// #define __PRINT__

int M, N;

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

vector<bool> is_prime(1000001, true);

void traversal(int n) {
    is_prime[0] = false; // 0은 소수가 아니므로 false로 설정
    is_prime[1] = false; // 1도 소수가 아니므로 false로 설정

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    traversal(N);

    for (int i = M; i <= N; i++) {
        if (is_prime[i])
            cout << i << "\n";
    }
}
