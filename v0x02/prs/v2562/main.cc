#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    pair<int,int> MAX;
    MAX=make_pair(0,0);
    // 앞에가 인덱스
    int input;
    for(int i=0;i<9;i++){
        cin>>input;
        if(input>MAX.second){
            MAX.second=input;
            MAX.first=i;
        }
    }
    cout<<MAX.second<<"\n"<<MAX.first+1;
}