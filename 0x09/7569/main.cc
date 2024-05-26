#include<bits/stdc++.h>
#define X first
#define Y second

int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int board[102][102][102];
int dist[102][102][102];

using namespace std;


int main(){
	ios::sync_with_stdio(false),cin.tie(NULL);


	int N,M,H;cin>>M>>N>>H;

	queue

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<H;k++){
				cin>>board[i][j][k];
				if(board[i][j][k]==0)
					dist[i][j][k]=-1;
				else if(board[i][j][k]==1)

			}
		}
	}
