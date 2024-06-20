#include<bits/stdc++.h>
using namespace std;

int n[11];

int main(){
	int T;
	cin>>T;
	n[1]=1;

	for(int i=0;i<T;i++){
		cin>>n;

		for(int j=2;j<=n;j++){
			n[j]=n[j-1]+1;




