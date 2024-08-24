#include<bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> s;

bool compare(string a, string b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		string name,log;
		cin>>name>>log;
		if(log=="enter")
			s.insert(name);
		else
			s.erase(name);
	}

	vector<string> ans(s.begin(),s.end());
	sort(ans.begin(),ans.end(),compare);

	for(auto it:ans)
		cout<<it<<"\n";
}


