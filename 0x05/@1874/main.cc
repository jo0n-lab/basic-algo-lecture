#include<bits/stdc++.h>
using namespace std;

bool isGreater(int i, int j){
	return (i>j);
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int n;cin>>n;
	int arr[n];
	
	stack<int> s1;
	stack<int> s2; s2.push(-1);
	string ans="";
	
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=n;i>0;i--) s1.push(i);

	for(int i=0;i<n;i++){
		while(s1.size()&&s2.top()!=arr[i]){
			s2.push(s1.top());
			s1.pop();
			ans+="+\n";
		}
		if(!s1.size()&&(s2.top()!=arr[i])){
			ans="NO";
			break;
		}
		s2.pop();
		ans+="-\n";
	}
	cout<<ans;
}


// 사실,, arr 도 필요없고, s1 또한 필요없다.
// 출력될 순서는 cin>>t 로 당장 받을 수 있고,,
// s1 또한 한번 pop 되면 다시 push 될 일이 없기 때문이다!
