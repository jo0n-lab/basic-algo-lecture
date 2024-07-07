#include <bits/stdc++.h>
using namespace std;

//#define __DEBUG__
//#define __INPUT__
//#define __PRINT__

int N, S;
int num[22];
int vis[22];
int ans = 0;
static vector<int> print_v;

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

void print_case() {
    for (int i = 0; i < print_v.size(); i++)
        cout << print_v[i] << " ";
    cout << "\n";
}

void func(int cur) {
    static int sum = 0;
    static int cnt = 0;
    for (int i = cur; i < N; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            sum += num[i];
            cnt++;
#ifdef __DEBUG__
            print_v.push_back(num[i]);
#endif
            if (sum == S && cnt != 0) {
                ans++;
#ifdef __DEBUG__
                print_config(to_string(ans) + "st success case");
                print_case();
#endif
            }

            func(i + 1);
#ifdef __DEBUG__
            print_v.pop_back();
#endif
            vis[i] = 0;
            sum -= num[i];
            cnt--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> num[i];

#ifdef __INPUT__
    print_config("INPUT");
    cout << N << " " << S << "\n";
    for (int i = 0; i < N; i++)
        cout << num[i] << " ";
    cout << "\n";
#endif

#ifdef __DEBUG__
    print_config("it begins");
#endif

    func(0);
    cout << ans;
}
