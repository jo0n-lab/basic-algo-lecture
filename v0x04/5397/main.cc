#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	int N;cin>>N;
	
	for(int i=0;i<N;i++){
		list<char> L;
	
		string sentence;cin>>sentence;
	
		char c;
	
		list<char>::iterator cursor=L.begin();
		
		for(int i=0;i<sentence.length();i++){
			c=sentence[i];
			if(c=='>'&&cursor!=L.end()) cursor++;
			else if(c=='<'&&cursor!=L.begin()) cursor--;
			else if(c=='-'&&cursor!=L.begin()) {
				cursor--;
				cursor=L.erase(cursor);
			}
			else if(c!='>'&&c!='<'&&c!='-'){
				L.insert(cursor,c);
			}
		}
		for(auto i : L) cout<<i;
		cout<<"\n";
	}
}
	
		


	

