#include<bits/stdc++.h>

using namespace std;

void printstack(stack<long long> s){
	stack<long long> s_print;
	while(!s.empty()){
		s_print.push(s.top());
		s.pop();
	}
	while(!s_print.empty()){
		cout<<s_print.top()<<" ";
		s_print.pop();
	}
	cout <<":::";
}

void printstack2(stack<long long> s1, stack<long long> s2){
	printstack(s1);printstack(s2);

	cout<<"\n";

}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	int N;cin>>N;
	int ans[N];fill(ans,ans+N,0);
	
	stack<long long> s1;
	stack<long long> s2;

	long long input;
	for(int i=0;i<N;i++) {
		cin>>input;
		s1.push(input);
	}

	//printstack(s1);

	int s1_pos=N-1;
	int s2_pos=N-1;

	s2.push(1000000001);

	while(!s1.empty()&&!s2.empty()){
		while(!s1.empty()&&(s2.top()>s1.top())){
			s2.push(s1.top());s1.pop();
			s2_pos--;
		}
		s1_pos=s2_pos-1;
		while((!s1.empty()&&!s2.empty())&&(s2.top()<s1.top())){
	//		cout<<s1_pos<<" ";
			s2.pop();
			s2_pos++;
		}
		printstack2(s1,s2);
	}
	
}



