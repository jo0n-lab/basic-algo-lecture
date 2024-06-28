#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define month first
#define day second

struct flower {
    pair<int, int> start;
    pair<int, int> end;
};
int N;
flower flowers[100002];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

bool compare_date(pair<int,int> a,pair<int,int> b){
	if(a.month!=b.month)
		return a.month<b.month;
	if(a.day!=b.day)
		return a.day<b.day;
	return false;
}

bool compare_flower(flower a, flower b) {
	if(compare_date(a.start,b.start))
			return compare_date(a.start,b.start);
	if(compare_date(a.end,b.end))
			return !compare_date(a.end,b.end);
	return false;


//    if (a.start.month != b.start.month)
//        return a.start.month < b.start.month;
//    if (a.start.day != b.start.day)
//        return a.start.day < b.start.day;
//    if (a.end.month != b.end.month)
//        return a.end.month > b.end.month;
//    if (a.end.day != b.end.day)
//        return a.end.day > b.end.day;
//    return false;
}

bool cover(flower f,pair<int,int> d){
	if(compare_date(f.end,d))	



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        flower f;
        cin >> f.start.month >> f.start.day;
        cin >> f.end.month >> f.end.day;
        flowers[i] = f;
    }
    sort(flowers, flowers + N, compare_flower);

#ifdef __INPUT__
    print_config("INPUT");
    for (int i = 0; i < N; i++) {
        pair<int, int> s = flowers[i].start;
        pair<int, int> e = flowers[i].end;
        cout << s.month << " " << s.day << " " << e.month << " " << e.day
             << "\n";
    }
#endif

//	int ans=0x7f7f7f7f;
//	pair<int,int> until={2,28};
//	for(int i=0;i<N;i++){

		

}
