#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int heights[9];
    int sum=0;
    for(int i=0;i<9;i++) {
        cin>>heights[i];
        sum+=heights[i];
    }

    int target=sum-100;
    sort(heights,heights+9);

    int spos=0; int epos=8;
    while(heights[spos]+heights[epos]!=target){
        if(heights[spos]+heights[epos]<target) spos++;
        else if(heights[spos]+heights[epos]>target) epos--;
    }

    for(int i=0;i<9;i++){
        if(i==epos || i==spos) continue;
        cout<<heights[i]<<" ";   
    }
     
}