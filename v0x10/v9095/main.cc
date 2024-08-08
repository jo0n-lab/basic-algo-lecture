#include <bits/stdc++.h>
using namespace std;

int n[11];

int main() {
    int T;
    cin >> T;
    n[1] = 1;
    n[2] = 2;
	n[3] =4;

    for (int i = 0; i < T; i++) {
		int input;
        cin >> input;

        if (n[input] != 0) {
            cout << n[input] << "\n";
            continue;
        }

        for (int j = 4; j <= input; j++) {
            if (n[j] != 0) continue;
            n[j] += n[j - 1];
            n[j] += n[j - 2];
            n[j] += n[j - 3];
        }

		cout<<n[input]<<"\n";
    }
}
