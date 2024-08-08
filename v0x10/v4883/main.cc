#include<bits/stdc++.h>
using namespace std;

//#define __INPUT__
//#define __PRINT__
//#define __DEBUG__

int N;
int board[1000002][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K=1;
	while(1){
		cin>>N;
		if(N==0) break;
		for(int i=0;i<N;i++){
			for(int j=0;j<3;j++){
				cin>>board[i][j];
			}
		}
		board[0][0]=board[0][1];
		board[0][2]+=board[0][1];


#ifdef __INPUT__
		cout<<"INPUT\n";
		for(int i=0;i<N;i++){
			for(int j=0;j<3;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
#endif




		for(int i=1;i<N;i++){
			board[i][0]+=min(board[i-1][0],board[i-1][1]);
			board[i][1]+=min({board[i][0],board[i-1][0],board[i-1][1],board[i-1][2]});
			board[i][2]+=min({board[i][1],board[i-1][1],board[i-1][2]});
		}

		
#ifdef __DEBUG__
		cout<<"DEBUG\n";
		for(int i=0;i<N;i++){
			for(int j=0;j<3;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
#endif

		cout<<K++<<". "<<board[N-1][1]<<"\n";
	}
}
