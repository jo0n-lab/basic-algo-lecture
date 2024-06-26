#include <bits/stdc++.h>
using namespace std;

//#define __DEBUG__
//#define __INPUT__
//#define __PRINT__

#define INF 0x7f7f7f7f
#define lower first
#define upper second

int N;
pair<int, int> table[200002];
int booked[200002];
int back;

vector<vector<pair<int, int>>> v_print;

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

void print_status(int idx) {
    vector<pair<int, int>> tmp = v_print[idx];
    print_config(to_string(idx + 1) + "st room");
    for (int i = 0; i < tmp.size(); i++)
        cout << "[" << tmp[i].lower << " " << tmp[i].upper << "] ";
    cout << "\n";
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.upper == b.upper)
        return a.lower < b.lower;
    return a.upper < b.upper;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int k = 0; k < N; k++) {
        int i, j;
        cin >> i >> j;
        table[k] = {i, j};
    }
    sort(table, table + N, compare);

#ifdef __INPUT__
    print_config("INPUT");
    for (int i = 0; i < N; i++)
        cout << table[i].lower << " " << table[i].upper << "\n";
    cout << "\n";
#endif

    int back = 1;
    booked[back] = -1;
    // last index of booked be the answer
    int gap = INF;

#ifdef __DEBUG__
    v_print.push_back({});
#endif

    for (int i = 0; i < N; i++) {
        int j = back;
        bool is_contain = false;
#ifdef __DEBUG__
		cout<<"\n\n";
		print_config("CASE BEGINS");
#endif
        for (; j >= 1; j--) {

#ifdef __DEBUG__		
			cout<<booked[j]<<"\n";
#endif


            if (booked[j] <= table[i].lower) {
                booked[j] = table[i].upper;
#ifdef __DEBUG__
                v_print[j - 1].push_back(table[i]);
#endif
                is_contain = true;
                break;
            }
        }

        if (!is_contain) {
            booked[++back] = table[i].upper;
#ifdef __DEBUG__
            v_print.push_back({table[i]});
#endif
        }
#ifdef __DEBUG__
        print_config("WHOLE STATUS");
        for (int i = 0; i < v_print.size(); i++)
            print_status(i);
        for (int i = 1; i <= back; i++)
            cout << booked[i] << " ";
        cout << "\n";
#endif
    }


    cout << back;
}
