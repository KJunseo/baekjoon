#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int answer[11];
vector<vector<int> > arr;
vector<vector<int> > visit;

void bfs(int y, int x, int cnt) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visit[y][x] = cnt;
    answer[cnt]++;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) 
                continue;

            if(visit[ny][nx]) 
                continue;

            if(!arr[ny][nx])
                continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx] = cnt;
            answer[cnt]++;
        }
    }

}

int main(void) {
    scanf("%d", &n);

    arr.resize(n);
    visit.resize(n);
    for(int i = 0; i < arr.size(); i++) {
        arr[i].resize(n);
        visit[i].resize(n);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int cnt = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 0) continue;
            if(visit[i][j]) continue;
            bfs(i, j, cnt);
            cnt++;
        }
    }

    printf("%d\n", cnt - 1);
    for(int i = 1; i < cnt; i++) 
        printf("%d ", answer[i]);

    return 0;
}
