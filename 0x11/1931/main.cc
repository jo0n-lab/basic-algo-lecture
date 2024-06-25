#include<bits/stdc++.h>
using namespace std;

#define __DEBUG__
#define __INPUT__
#define __PRINT__

#define upper first
#define lower second

int N;
pair<int,int> bound[100002];

void print_config(string s){
	cout.width(20);
	cout.fill('-');
	cout<<s<<"\n";
}

bool compare(pair<int,int> a, pair<int,int> b){
	return a<b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int k=0;k<N;k++){
		int i,j;
		cin>>i>>j;
		bound[k]={i,j};
	}
	sort(bound,bound+N);

#ifdef __PRINT__
	print_config("PRINT");
	for(int i=0;i<N;i++){
		cout<<bound[i].upper<<" "<<bound[i].lower<<"\n";
	}
#endif


	for(int i=0;i<N;i++){
		

}

	




