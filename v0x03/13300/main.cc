#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int arr[6][2];
	fill(&arr[0][0],&arr[5][2],0);

	int N,K;
	cin>>N>>K;
	int S,G;
	
	for(int i=0;i<N;i++){
		cin>>S>>G;
		arr[G-1][S]++;
	}

	int result=0;

	for(int i=0;i<6;i++){
		result+=arr[i][0]/K+bool(arr[i][0]%K);
		result+=arr[i][1]/K+bool(arr[i][1]%K);
	}

	cout<<result;
}


