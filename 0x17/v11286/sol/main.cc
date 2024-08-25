#include<bits/stdc++.h>
using namespace std;

int N;
class cmp{
	public:
		bool operator() (int a,int b){
			if(abs(a)==abs(b))
				return a>0 && b<0;
			else
				return abs(a)>abs(b);
		}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, cmp> pq;
	cin>>N;

	for(int i=1;i<=N;i++){
		int input;cin>>input;
		if(input==0){
			if(pq.empty())
				cout<<"0\n";
			else{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
		else
			pq.push(input);
	}
}


