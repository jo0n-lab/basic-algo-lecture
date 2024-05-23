#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	int N;cin>>N;
	string a,b;

	for(int i=0;i<N;i++){
		cin.ignore();
		cin>>a>>b;
	
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
	
		int pos=0;

		string ans="Possible";
		for(int i=0;i<a.length();i++){
			if(a[i]!=b[i]){
				ans="Impossible";
				break;
			}
		}
		cout<<ans<<"\n";
	}

}

