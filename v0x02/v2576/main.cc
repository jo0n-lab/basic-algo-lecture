#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int sum=0;
    int m=100;
    int input;

    for(int i=0;i<7;i++){
        cin>>input;
        if(input%2){
            sum+=input;
            if(input<m) m=input;
        } 
    }
    if(m==100) cout<<-1;
    else cout<<sum<<"\n"<<m;
    
}