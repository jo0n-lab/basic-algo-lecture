#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __PRINT__
#define __DEBUG__

string s1;
string s2;

int cache[1002][1002];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s1>>s2;
	
	string source;
	string target;
	if(s1.length<=s2.length()){
		source=s1;
		target=s2;
	}else{
		source=s2;
		target=s1;
	}

	int n=source.length();
	int m=target.length();
	int start=m;
	
	for(int i=0;i<n;i++){
		char c=source[i];
		for(int j=0;j<m;j++){
			if(target[j]!=c) continue;


		

	}





