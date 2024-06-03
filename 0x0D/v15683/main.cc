#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dyn_area;
int dyn_board[10][10];
int const_board[10][10];

vector<pair<int, int>> cctv;

void uncover(int xpos, int ypos, int dir) {
    while (xpos >= 0 && xpos < N && ypos >= 0 && ypos < M &&
           dyn_board[xpos][ypos] != 6) {
        if (dyn_board[xpos][ypos] == 0) {
            dyn_board[xpos][ypos] = 7;
            dyn_area--;
        }
        xpos += dx[dir];
        ypos += dy[dir];
    }
}

void print_board(){
	cout<<"\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<const_board[i][j];
		}
		cout<<"\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int const_area = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int input;
            cin >> input;
            if (input == 0)
                const_area++;
            else if (input < 6 && input > 0)
                cctv.push_back({i, j});
            //인덱스로 바로 접근하여 cctv 유형 확인할 수 있음
            const_board[i][j] = input;
        }
    }
	
	//print_board();

    int times = 1 << (2 * cctv.size());
    int ans = M * N;

   for (int pic = 1; pic <= times; pic++) {
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < M; j++) {
               dyn_board[i][j] = const_board[i][j];
           }
       }
       dyn_area = const_area;
       int tmp = pic;

       for (int i = 0; i < cctv.size(); i++) {

           int dir = tmp % 4;
           tmp /= 4;

           int nx = cctv[i].X;
           int ny = cctv[i].Y;
           int cctv_no = const_board[nx][ny];

           if (cctv_no == 1)
                uncover(nx, ny, dir);
           else if (cctv_no == 2) {
              uncover(nx, ny, dir);
              uncover(nx, ny, (dir + 2) % 4);
          } else if (cctv_no == 3) {
              uncover(nx, ny, dir);
              uncover(nx, ny, (dir + 1) % 4);
          } else if (cctv_no == 4) {
              uncover(nx, ny, dir);
              uncover(nx, ny, (dir + 1) % 4);
              uncover(nx, ny, (dir + 2) % 4);
          } else if (cctv_no == 5) {
              uncover(nx, ny, dir);
              uncover(nx, ny, (dir + 1) % 4);
              uncover(nx, ny, (dir + 2) % 4);
              uncover(nx, ny, (dir + 3) % 4);
          }
       }
       ans = min(ans, dyn_area);
   }
    cout << ans;
}
