#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int n;
int board[2][1000];
int ver[2][1] = {{1}, {1}};
int hor[1][2] = {1, 1};

int ans[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= n; i++) {
        ans[i] += ans[i - 1];
        ans[i] += ans[i - 2];
		ans[i]%=10007;
#ifdef __DEBUG__
		if(ans[i]<0) cout<<"out of data range: "<<i<<"st "<<ans[i]<<"\n";
#endif
    }

    cout << ans[n];
}
