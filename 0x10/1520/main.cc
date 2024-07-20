#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

int M,N;
int board[502][502];

void print_config(string s){
	cout.width(20);
	cout.fill(' ');
	cout<<s<<"\n";
}

void INPUT(){
	cin>>M>>N;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>board[i][j];
		}
	}
#ifdef __INPUT__
	print_config(__func__);
	cout<<M<<" "<<N<<"\n";
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
#endif
}



