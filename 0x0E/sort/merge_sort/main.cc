#include <bits/stdc++.h>
using namespace std;

#define __DEBUG__

int n = 10;
int arr[10] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고
                  // 있을 변수

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는
// 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en) {
#ifdef __DEBUG__
	if(en>=n)
		cout<<"something wrong: "<<st<<" "<<en<<"\n";
#endif

    int mid = (st + en) / 2;
    int apos = st;
    int bpos = mid + 1;
    int mpos = st;

    while (apos <= mid && bpos <= en) {
        if (arr[apos] <= arr[bpos]) {
            tmp[mpos] = arr[apos];
            apos++;
        } else {
            tmp[mpos] = arr[bpos];
            bpos++;
        }
        mpos++;
    }
#ifdef __DEBUG__
    cout << "segfault under this \n";
#endif
    for (; apos <= mid; apos++)
        tmp[mpos++] = arr[apos];
    for (; bpos <= en; bpos++)
        tmp[mpos++] = arr[bpos];

    for (int i = st; i <= en; i++)
        arr[i] = tmp[i];

#ifdef __DEBUG__
    if (mpos != en+1) {
        cout << "ERROR!!! last position doen't match: ";
        cout << mpos << " " << en << "\n";
    }
#endif
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en) {
    if (st == en) {
#ifdef __DEBUG__
        cout << "returns " << st << " " << en << "\n";
#endif
        return; // 길이 1인 경우
    }
    int mid = (st + en) / 2;
#ifdef __DEBUG__
    cout << "segfault under this " << to_string(mid) << "\n";
#endif
    merge_sort(st, mid); // arr[st:mid]을 정렬한다.
    merge_sort(mid+1, en); // arr[mid:en]을 정렬한다.
    merge(st, en);       // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    merge_sort(0, n-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' '; // -53 3 12 15 16 22 23 25 46 357
}
