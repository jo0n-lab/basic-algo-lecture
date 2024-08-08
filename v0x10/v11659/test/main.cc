#include<bits/stdc++.h>
using namespace std;

int main(){
	int s; cin>>s;
	vector<int> a(s);
	for(int i=0;i<s;i++)
		cin>>a[i];

	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
}
