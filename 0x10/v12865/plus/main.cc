#include <bits/stdc++.h>
using namespace std;

// #define __INPUT__
// #define __PRINT__
// #define __DEBUG__

int N, K;
int w[102];
int v[102];
int cache[102][100002];

int tmp[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
        cin >> v[i];
    }

    for (int i = 1; i <= N; i++) {
        int W = w[i];
        int V = v[i];
        for (int j = 1; j < W; j++)
            cache[i][j] = cache[i - 1][j];
        for (int j = W; j <= K; j++) {
			if(cache[i-1][j]<=cache[i-1][j-W]+V){
				cache[i][j]=cache[i-1][j-W]+V;
				tmp[j]=i;
			}else{
				cache[i][j]=cache[i-1][j];
			}
		}
    }

#ifdef __DEBUG__
    cout << "DEBUG\n";
    for (int i = 1; i <= N; i++) {
        cout << "value: " << v[i] << " | ";
        for (int j = 1; j <= K; j++) {
            cout.width(3);
            cout.fill(' ');
            cout << cache[i][j] << " ";
        }
        cout << "\n";
    }
#endif

    int max_id=0;
    for (int j = 1; j <= K; j++){
		if(cache[N][max_id]<=cache[N][j])
			max_id=j;
	}

    cout << cache[N][max_id]<<"\n";

	int i=max_id;
	while(i>0){
		int idx=tmp[i];
		cout<<w[idx]<<" "<<v[idx]<<"\n";
		i-=w[idx];
	}
		

}
