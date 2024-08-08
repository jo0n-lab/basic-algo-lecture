#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

int N;
int points[302];
int gained[302][2];
//0: skipped 2 steps
//1: continuosly stepped

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>points[i];
		gained[i][0]=points[i];
		gained[i][1]=points[i];
	}


//	gained[1][0]=points[1];
//	gained[1][1]=points[1];
//	gained[2][0]=points[2];
//	gained[2][1]=points[1]+points[2];
	gained[2][1]+=points[1];

	for(int i=3;i<=N;i++){
		gained[i][0]+=max(gained[i-2][0],gained[i-2][1]);
		gained[i][1]+=gained[i-1][0];
	}

	cout<<max(gained[N][0],gained[N][1]);
}


	
