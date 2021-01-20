#include <vector>

using namespace std;

const int INF = 987654321;

int visit[31][31];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int cy, cx;
int temp;

void init(int n) {
    temp = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visit[i][j] = 0;
        }
    }
}

void dfs(int y, int x, int num, int cnt, vector<vector<int>> board, int n) {
    if(board[y][x] == num) {
        if(temp > cnt) {
            temp = cnt;
            cy = y;
            cx = x;
        }
        return;
    }
    
    visit[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny == -1)
            ny = n - 1;
        if(nx == -1)
            nx = n - 1;
        if(ny == n)
            ny = 0;
        if(nx == n)
            nx = 0;
        
        if(!visit[ny][nx]) {
            dfs(ny, nx, num, cnt + 1, board, n);
        }
    }
    
    visit[y][x] = 0;
}

int solution(int n, vector<vector<int>> board) {
    int answer = 0;
    
    for(int i = 1; i <= n * n; i++) {
        init(n);
        dfs(cy, cx, i, 0, board, n);
        answer += (temp + 1);
    }

    return answer;
}