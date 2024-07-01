#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N, S;
int num[22];
int vis[22];

int cnt=0;
vector<int> V;

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

void print_case(){
	print_config(to_string(cnt)+"st case");
	for(auto i=V.begin();i!=V.end();i++)
		cout<<*i<<" ";
	cout<<"\n";
}

void func(int sum, int cur) {
    if (sum == S) {
        cnt++;
#ifdef __DEBUG__
		print_case();
#endif
        return;
    } else {
        if (vis[cur] == 0) {
            vis[cur] = 1;
#ifdef __DEBUG__
			cout<<"cur: "<<cur<<"\n";
#endif
#ifdef __DEBUG__
			V.push_back(num[cur]);
#endif
			for(int i=1;i<N-cur;i++)
            	func(sum + num[cur], cur + i);
#ifdef __DEBUG__
			V.pop_back();
#endif 
            vis[cur] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++){
		int input;cin>>input;
        num[i]=input;
		if(input==0) cnt++;
	}
	for(int i=0;i<N;i++)
    	func(0, i);
	cout<<cnt;
}
