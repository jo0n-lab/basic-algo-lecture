#include <bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

#define X first
#define Y second

int M, N;
int board[502][502];
int cache[502][502];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

stack<pair<int, int>> s;
int ans = 0;

// DFS could be impl in 2 ways:
// 1. using stack
// 2. recursion
// for this case use recursion
//
// take advantage of history
// 1. remember failed case


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
	fill_n(&cache,502*502,4);
	
	s.push({0,0});
	while(!s.empty()){
		pair<int,int> cur=s.top();
		int cnt=0;
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];

			//some conditions: continue;
			s.push({nx,ny});
		}
		if(cache[cur.X][cur.Y]==0){






}
