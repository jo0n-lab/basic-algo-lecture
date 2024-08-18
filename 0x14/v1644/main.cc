#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRINT__
// #define __DEBUG__

int N;
vector<bool> is_prime(4'000'002, true);
vector<int> prime;

void sieve(int num) {
    is_prime[1] = false;
    int i = 2;
    for (; i * i <= num; i++) {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= num; j += i)
            is_prime[j] = false;
        prime.push_back(i);
    }
    for (; i <= num; i++)
        if (is_prime[i])
            prime.push_back(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    sieve(N);
    int prime_n = prime.size();

#ifdef __DEBUG__
    cout << "DEBUG:: ";
    for (int i = 0; i < prime_n; i++)
        cout << prime[i] << " ";
    cout << "\n";
#endif

    int spos = 0;
    int epos = 0;
    int ans = 0;
    int tmp = 0;

    while (spos < prime_n && epos < prime_n) {
        if (tmp >= N) {
            if (tmp == N)
                ans++;
            tmp -= prime[spos++];
        } else {
            tmp += prime[epos];
            epos++;
        }
    }
    for (; spos < prime_n; spos++) {
        if (tmp < N)
            break;
        else if (tmp == N)
            ans++;
        tmp -= prime[spos];
    }

    cout << ans;
}
