#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    int input;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            cin>>input;
            sum+=input;
        }
        if(sum==4) cout<<"E";
        else if(sum==3) cout<<"A";
        else if(sum==2) cout<<"B";
        else if(sum==1) cout<<"C";
        else cout<<"D";
        cout<<"\n";
    }

}