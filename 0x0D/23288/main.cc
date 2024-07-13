#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define X first
#define Y second

int N,M;
int K;
int board[22][22];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int sum=0;
int score[7];
int dice[4][3]={
	{0,2,0},
	{4,1,3},
	{0,5,0},
	{0,6,0}
};

void print_config(string s){
	cout.width(25);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_board(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout.width(2);
			cout.fill(' ');
			cout<<board[i][j];
		}
		cout<<"\n";
	}
}

int BFS(pair<int,int> target){
	int num=board[target.X][target.Y];
	if(score[num]>0) return score[num];

	int cnt=1;
	int vis[22][22];
	fill_n(&vis[0][0],22*22,0);

	queue<pair<int,int>> Q;
	vis[target.X][target.Y]=1;
	Q.push(target.X,target.Y);

	while(!Q.empty()){
		pair<int,int> cur=Q.front();
		Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
		
			if(vis[nx][ny]==1) continue;
			if(nx<1 || nx>N || ny<1 || ny>M) continue;

			vis[nx][ny]=1;
			cnt++;
			Q.push({nx,ny});
		}
	}
	score[num]=num*cnt;
	return score[num];
}

int dice_num;
pair<int,int> cur_pos;

int which_dir(int cur_dir){
	int A=dice_num;
	int B=board[cur_pos.X][cur_pos.Y];

	if(A>B) return (cur_dir+1)%4;
	else if(A<B) return (cur_dir+3)%4;	
	return cur_dir;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N>>M;
	cin>>K;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>board[i][j];
		}
	}
	
#ifdef __INPUT__
	print_config("INPUT");
	print_board();
#endif

	cur_pos={1,1};
	dice_num=6;
	BFS(cur_pos);
	for(int i=0;i<K;i++){
		

}
