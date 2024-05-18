#include<iostream>

using namespace std;

int main(){
    int num;
    int narr[2]={3,5};

    cin>>num;
    int result=0;

    for(int i=1;i<=num;i++){
        if(!(i%narr[0]) || !(i%narr[1])) result+=i;
    }

    cout<<result;
}