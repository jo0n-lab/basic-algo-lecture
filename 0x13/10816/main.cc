#include <bits/stdc++.h>
using namespace std;

//#define __INPUT__
//#define __PRINT__
//#define __DEBUG__

int N, M;
int arr[500002];

int find_idx(int target, int dir){
	int st = 1;
	int en = N;
	int mid = (st + en) / 2;
	int sign=0;

	while(st<=en){
		//arr[mid-1]<target
		if(arr[mid]==target){
			sign=1;
			if(arr[mid+dir]!=target){
#ifdef __DEBUG__
				if(dir==-1)
					cout<<target<<"'s left found as "<<arr[mid+dir]<<" "<<mid<<"\n";
				else
					cout<<target<<"'s right found as "<<arr[mid+dir]<<" "<<mid<<"\n";
#endif
				return mid;
			}
			else if(dir==-1)
				en=mid-1;
			else 
				st=mid+1;
		}
		else if(arr[mid]<target)
			st=mid+1;
		else if(arr[mid]>target)
			en=mid-1;
		mid=(st+en)/2;
	}

	return sign;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> M;

    sort(arr + 1, arr + N + 1);

#ifdef __INPUT__
	cout<<"INPUT\n";
	for(int i=1;i<=N;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
#endif

    for (int i = 1; i <= M; i++) {
        int t;
        cin >> t;

		int left=find_idx(t,-1);
		int right=find_idx(t,1);
		int sign=left;
		
	cout<<right-left<<" ";

    }
}
