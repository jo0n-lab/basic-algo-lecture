#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

#define X first
#define Y second

int N;
int board[5][22][22];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void print_board(int page){
	cout<<"--------board---------"<<"\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<board[page][i][j];
		}
		cout<<"\n";
	}
	cout<<"--------board---------"<<"\n";
}

bool move(int dir,int page) {
	//0 left
	//1 right
	//2 up
	//3 down
	
	if(dir==0){
		for(int i=0;i<N;i++){
			queue<int> Q;
			int tmp=board[page][i][0];
			// 최초값이 0인 경우 고려
			for(int j=1;j<N;j++){
				if(!board[page][i][j])
					continue;
				if(tmp==board[page][i][j] && tmp)
					tmp*=2;
				else{
					Q.push(tmp);
					tmp=board[page][i][j];
				}
			}
			while(!Q.empty()){

		}	
	}







int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//	exc: 보드 1칸짜리일때

	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int input;cin>>input;
			for(int p=0;p<5;p++){
				board[p][i][j]=input;
			}
		}
	}
#ifdef __INPUT__
	print_board(0);
#endif

	int n_cases=1<<(2*5); //경우의 수: 4^5
	bool can_forward; //다음 단계로 나아갈 수 있는가?
	
	for(int cas=0;cas<n_cases;cas++){


