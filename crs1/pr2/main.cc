#include <iostream>

using namespace std;

// O(N^2)
int func2(int arr[], int N){
    for(int i=0;i<N;i++){
        if(arr[i]>100) continue;
        for(int j=i+1;j<N;j++){
            if(arr[j]>100) continue;
            if(arr[i]+arr[j]==100) return 1;
        }
    }
    return 0;
}

int main(){
    cout<<"hel";
}