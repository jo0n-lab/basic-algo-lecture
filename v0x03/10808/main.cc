#include<bits/stdc++.h>

using namespace std;

int arr[26];

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	string input;
	cin>>input;
	fill(arr,arr+26,0);

	for(int i=0;i<input.length();i++)	arr[int(input[i]-'a')]++;
	for(int i=0;i<26;i++) cout<<arr[i]<<" ";

}
