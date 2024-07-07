#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N;
int arr[102];

bool is_prime(int num) {
    if (num == 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int num = arr[i];
        if (is_prime(num) == true)
            cnt++;
    }

    cout << cnt;
}
