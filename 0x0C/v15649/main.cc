#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N, M;
int num[10];
int is_used[10];

void func(int k) {
    if (k > M) {
        for (int i = 1; i <= M; i++)
            cout << num[i] <<" ";
		cout<<"\n";
        return;
    } else {
        for (int i = 1; i <= N; i++) {
            if (is_used[i] == 0) {
                is_used[i] = 1;
                num[k] = i;
                func(k + 1);
                is_used[i] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    func(1);
}
