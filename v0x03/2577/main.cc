#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int input;
	int mul=1;
	int arr[10];
	fill(arr,arr+10,0);

	for(int i=0;i<3;i++){
		cin>>input;
		mul*=input;
	}

	while(mul){
		arr[mul%10]++;
		mul/=10;
	}

	for(int i=0;i<10;i++) cout<<arr[i]<<"\n";
}

