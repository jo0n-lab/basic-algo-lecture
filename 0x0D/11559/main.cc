#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define X first
#define Y second

int R,C;
char board[12+2][6+2];
int vis[12+2][6+2];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_board(){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void fpop(){
	fill_n(&vis[0][0],14*8,0);
	queue<pair<int,int>> Q[5];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(board[i][j]=='R')
				Q[0].push({i,j});
			else if(board[i][j]=='G')
				Q[1].push({i,j});
			else if(board[i][j]=='B')
				Q[2].push({i,j});
			else if(board[i][j]=='P')
				Q[3].push({i,j});
			else if(board[i][j]=='Y')
				Q[4].push({i,j});
		}
	}
	for(int i=0;i<5;i++){
		int cnt=0;
		pair<int,int> cur=Q.front();
		vis[cur.X][cur.Y]=1;
		while(!Q[i].empty()){
			cur=Q.front();
			for(int dir=0;dir<4;dir++){
				int nx=cur.X+dx[dir];
				int ny=cur.Y+dy[dir];
				if(nx<0||nx>=R||ny<0||ny>=C)
					continue;
				if(vis[nx][ny]==1)
					continue;
				vis[nx][ny]=1;
				cnt++;
			}
		}





void fall(){
	for(int j=0;j<C;j++){
		pair<int,int> zero={0,j};
		for(int i=R-1;i>=0;i--){
			if(board[i][j]=='.'){
				zero={i,j}
				break;
			}
		}
		if(zero.X==0) continue;
		queue<pair<int,int>> tmp;
		for(int i=zero.X-1;i>=0;i--){
			if(board[i][j]!='.'){
				tmp.push({i,j});
			}
		}
		pair<int,int> pos=zero;
		while(!tmp.empty()){
			pair<int,int> cur=tmp.front();
			tmp.pop();
			board[pos.X][pos.Y]=board[cur.X][cur.Y];
			board[cur.X][cur.Y]='.';
			pos={pos.X-1,pos.Y};
		}
	}
}





int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	R=12;
	C=6;

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>board[i][j];
		}
	}
	
#ifdef __INPUT__
	print_config("INPUT");
	print_board();
#endif



}
