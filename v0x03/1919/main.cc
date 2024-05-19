#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int alpha[26];fill(alpha,alpha+26,0);
	string a,b;cin>>a>>b;

	for(int i=0;i<a.length();i++) alpha[int(a[i]-'a')]++;
    for(int i=0;i<b.length();i++) alpha[int(b[i]-'a')]--;

	int result=0;

	for(int i=0;i<26;i++) result+=abs(alpha[i]);

	cout<<result;
}
	
