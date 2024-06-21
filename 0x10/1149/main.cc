#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define INF 1001

tuple<int,int,int> costs[1002];
int colors[1002]; //R:0 G:1 B:2
int N;

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_input(){
	print_config("INPUT");
	for(int i=0;i<N;i++){
		cout<<get<0>(costs[i])<<" ";
		cout<<get<1>(costs[i])<<" ";
		cout<<get<2>(costs[i])<<"\n";
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int i=0;i<N;i++){
		int R,G,B;
		cin>>R>>G>>B;
		costs[i]={R,G,B};
	}

#ifdef __INPUT__
	print_input();
#endif





}
