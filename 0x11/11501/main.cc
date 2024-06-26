#include <bits/stdc++.h>
using namespace std;

// #define __DEBUG__
// #define __INPUT__
// #define __PRINT__

int T, N;
long long int value[1000003];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

int right_max(int right){
	int maxima=0;
	int max_i=right;
	for(int i=right;i<=N;i++){
		if(maxima<=value[i]){
			maxima=value[i];
			max_i=i;
		}
	}
	return max_i;
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> value[i];

#ifdef __INPUT__
        print_config(to_string(t + 1) + "st INPUT");
        for (int i = 1; i <= N; i++)
            cout << value[i] << " ";
        cout << "\n";
#endif

		vector<int> right_maxima;
		int pos=1;
		while(pos<=N){
			pos=right_max(pos);
			right_maxima.push_back(pos);
			pos++;
		}

        for (int i = 1; i <= N; i++) {
			int max_i=right_maxima(i);
            if (value[i] <= value[i + 1]) {
                paid += value[i];
                cnt++;
                continue;
            }
            ans += value[i] * cnt - paid;
            cnt = 0;
            paid = 0;
        }
        cout << ans << "\n";
    }
}
