#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N, C;
int M;
tuple<int, int, int> info[10002];
queue<pair<int,int>> dest[2002];
int vis[2002];

int store[2002];

void print_config(string s) {
    cout.width(20);
    cout.fill('-');
    cout << s << "\n";
}

bool compare(tuple<int,int,int> a,tuple<int,int,int> b){
	if(get<1>(a)==get<1>(b)){
		if(get<0>(a)==get<0>(b))
			return get<2>(a)<get<2>(b);
		return get<0>(a)<get<0>(b);
	}
	return get<1>(a)<get<1>(b);
}
	

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;
    cin >> M;

    for (int m = 0; m < M; m++) {
        int i, j, cnt;
        cin >> i >> j >> cnt;
        info[m] = {i, j, cnt};
    }
    sort(info, info + M,compare);

#ifdef __INPUT__
    print_config("INPUT");
    for (int i = 0; i < M; i++)
        cout << get<0>(info[i]) << " " << get<1>(info[i]) << " "
             << get<2>(info[i]) << "\n";
    cout << "\n";
#endif

	queue<tuple<int,int,int>> Q;
	for(int i=0;i<M;i++)
		Q.push(info[i]);

	int ans=0;
	int res=C;
	int vill=1;
	int pos=0;
	

	for(int vill=1;vill<=N;vill++){
		int src,dst,cnt;
		tie(src,dst,cnt)=info[pos];
	
		if(src==vill){
			int add=(res/cnt)*cnt+res%cnt;
			store[dst]+=add;
			res-=add;
			pos++;
			//continue;
		}
		else if(src>=vill){
			int add=(res/cnt)*cnt+res%cnt;
			res-=add;

		

		if(src>vill){
			ans+=(res/cnt)*cnt+res%cnt;
			if(res-tmp==0) {
				ans+=tmp;
				break;
			}
			int tmp;
			for(int i=pos;i<M;i++) {
				if(src<get<0>(info[i])) continue;
				vis[src<get<0>>(info[i])]=1;

		if(vill==dst) {
		if(vis[src]) {
			Q.pop();
			continue;
		}



		if(vill==dst){
			int add=(res/cnt)*cnt+res%cnt;
			res-=add;
			ans+=add;
		}
		if(vill==src){
			ans+=


	


		


}
