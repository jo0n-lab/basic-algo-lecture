#include <bits/stdc++.h>
using namespace std;

int M, N;

vector<bool> is_prime(1000001, true);

void traversal(int n) {
    is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
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
