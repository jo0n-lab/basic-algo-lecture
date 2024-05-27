#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int board[502][502];
int vis[502][502];


int main(){
	int n,m; cin>>n>>m;

	int ans=0;
	int ans1=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>board[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]||!board[i][j]) continue;

			queue<pair<int,int>> Q;
			Q.push({i,j});vis[i][j]=1;
			int tmp=1;
		
			while(!Q.empty()){
				pair<int,int> cur=Q.front(); Q.pop();
				for(int dir=0;dir<4;dir++){
					int nx=cur.X+dx[dir];
					int ny=cur.Y+dy[dir];
		
					if(nx<0||nx>=n||ny<0||ny>=m) continue;
					if(vis[nx][ny]||board[nx][ny]!=1) continue;
		
					vis[nx][ny]=1;Q.push({nx,ny});
					tmp++;
				}
			}
			ans=max(tmp,ans);
			ans1++;
		}
	}
	cout<<ans1<<"\n"<<ans;
}
		
