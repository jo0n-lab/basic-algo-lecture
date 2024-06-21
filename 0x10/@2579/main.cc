#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

struct stair {
    int point;
    int gain;
    bool is_continued;
};
stair stairs[305];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stairs[i].point;

    stairs[1].gain = stairs[1].point;
    stairs[1].is_continued = false;
    stairs[2].gain = stairs[1].gain + stairs[2].point;
    stairs[2].is_continued = true;

    for (int i = 3; i <= n; i++) {
        int one_step = stairs[i].gain = stairs[i - 1].gain + stairs[i].point;
        int two_step = stairs[i].gain = stairs[i - 2].gain + stairs[i].point;
        if (stairs[i - 1].is_continued || one_step <= two_step) {
            stairs[i].gain = two_step;
            stairs[i].is_continued = false;
        } else if (one_step > two_step) {
            stairs[i].gain = one_step;
            stairs[i].is_continued = true;
        }
    }

#ifdef __PRINT__
    cout.width(20);
    cout.fill('-');
    cout << "stairs gained"
         << "\n";
    for (int i = 1; i <= n; i++)
        cout << stairs[i].gain << " ";
    cout << "\n";
#endif

    cout << stairs[n].gain;
}
