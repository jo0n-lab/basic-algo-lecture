#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);

	list<char> s;
	string input_s;cin>>input_s;
	int M;cin>>M;

	for(int i=0;i<input_s.length();i++) 
		s.push_back(input_s[i]);
	list<char>::iterator cursor=s.end();

	string command_s;



//마지막엔 getline 첫 실행시 cin 으로 받아온 \n 남아있으므로..
//3번 돌더라도 실질적으로는 2번밖에 안돌음...
//따라서 cin 의 \n을 비워줘야: cin.ignore;


	cin.ignore();
	for(int i=0;i<M;i++) {
		getline(cin,command_s);
		if(command_s=="L" && cursor!=s.begin()) cursor--;
		else if(command_s=="D" && cursor!=s.end()) cursor++;
		else if(command_s=="B" && cursor!=s.begin()){
			cursor--;
			cursor=s.erase(cursor);
		}
		else if(command_s[0]=='P') s.insert(cursor,command_s[2]);

	}

	for(list<char>::iterator it=s.begin();it!=s.end();it++)
		cout<<*it;
}


