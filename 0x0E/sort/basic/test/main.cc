#include <bits/stdc++.h>
using namespace std;

int N;
int num[100002];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
       cin >> num[i];

	int min_id=min_element(num,num+6)-&num[0];
	cout<<min_id;

}
