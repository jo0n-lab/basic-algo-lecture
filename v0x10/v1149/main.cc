#include<bits/stdc++.h>
using namespace std;

//#define __DEBUG__
//#define __INPUT__
//#define __PRINT__


int costs[1002][3];
int houses[1002][3]; //R:0 G:1 B:2
int N;

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_input(){
	print_config("INPUT");
	for(int i=0;i<N;i++){
		cout<<costs[i][0]<<" ";
		cout<<costs[i][1]<<" ";
		cout<<costs[i][2]<<"\n";
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>costs[i][0]>>costs[i][1]>>costs[i][2];

#ifdef __INPUT__
	print_input();
#endif

	houses[1][0]=costs[1][0];
	houses[1][1]=costs[1][1];
	houses[1][2]=costs[1][2];
	int start=2;

	for(int i=start;i<=N;i++){
		houses[i][0]=min(houses[i-1][1],houses[i-1][2]) + costs[i][0];
		houses[i][1]=min(houses[i-1][0],houses[i-1][2]) + costs[i][1];
		houses[i][2]=min(houses[i-1][0],houses[i-1][1]) + costs[i][2];
	}

	cout<<min({houses[N][0],houses[N][1],houses[N][2]});
}
