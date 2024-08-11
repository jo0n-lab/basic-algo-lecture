#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

#ifdef __DEBUG__
#define __D1__
#define __D2__
#endif

int N;
int arr[1000002];
vector<int> v;

void print_config(string s){
	cout<<__FILE__<<"::"<<s<<": ";
}



int lower_idx(int target) {
    int st = 0;
    int en = v.size();
    while (st < en) {
        int mid = (st + en) / 2;
        if (v[mid] >= target)
            en = mid;
        else
            st = mid + 1;
#ifdef __D2__
		print_config(__func__);
        cout << "st & en " << st << " " << en << "\n";
#endif
    }
    return st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

#ifdef __INPUT__
    cout << "INPUT\n";
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
    cout << "\n";
#endif

    v.push_back(arr[1]);
    for (int i = 2; i <= N; i++) {
#ifdef __D1__
        cout << "DEBUG\n";
#endif
        int cur = arr[i];
        if (cur > v.back())
            v.push_back(cur);
        else if (cur < v.back()) {
            int idx = lower_idx(cur);
#ifdef __D1__
			print_config(__func__);
            cout << "cur & idx: " << cur << " " << idx << "\n";
#endif
            v[lower_idx(cur)] = cur;
        }
#ifdef __D1__
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
#endif
    }

    cout << v.size();
}
