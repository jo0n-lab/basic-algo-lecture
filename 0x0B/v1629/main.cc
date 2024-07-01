#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

// TODO implement func return $a^b$ mod m

int m;
long long func(int a, int b) {
    static long long result = 1;

    if (b == 1)  return a % m;
    long long res = func(a, b / 2);
    result = (res * res) % m;
    if (b % 2 == 1) result *= a % m;
    return result % m;
}

int main() {
    int a, b;
    cin >> a >> b >> m;

    long long ans = func(a, b);
    cout << ans;
}
