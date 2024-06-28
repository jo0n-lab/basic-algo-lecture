#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define X first
#define Y second

int N;
int board[1002][3];
int dist[1002][3];
pair<int,int> init;
pair<int,int> dir[3];

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_board(){
	print_config("BOARD");
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			if(init.X==i&&init.Y==j){
				cout<<"# ";
				continue;
			}
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void move(int x,int y){
	if(y==0){
		dir[0]={x+1,0};
		dir[1]={x+1,1};
		dir[2]={x+1,2};
	}
	else if(y==1){
		dir[0]={x+1,0};
		dir[1]={x+1,2};
	}
	else if(y==2){
		dir[0]={x+1,0};
		dir[1]={x+1,1};
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			cin>>board[i][j];
		}
	}

#ifdef __INPUT__
	print_board();
#endif

	for(int dir=0;dir<3;dir++){
		if(board[0][dir]==1) 
			dist[0][dir]=0x7f7f7f7f;
		else
			dist[0][dir]=abs(1-dir);
	}

	for(int i=1;i<N;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]==1){
				dist[i][j]=0x7f7f7f7f;
				continue;
			}
			int tmp[3];
			for(int dir=0;dir<3;dir++){
				if(board[i-1][dir]==1){
					tmp[dir]=0x7f7f7f7f;
					continue;
				}
				tmp[dir]=dist[i-1][dir]+abs(dir-j);
			}
			dist[i][j]=min({tmp[0],tmp[1],tmp[2]});
		}
	}

#ifdef __DEBUG__
	print_config("DIST");
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
#endif

	int ans=min({dist[N-1][0],dist[N-1][1],dist[N-1][2]});
	cout<<ans;
}





		



	



