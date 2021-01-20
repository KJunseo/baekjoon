#include <vector>

using namespace std;

int dy[] = {-1, 1};
int dx[] = {1, -1};

vector<vector<int>> solution(int n, bool horizontal) {
    vector<vector<int>> answer;
    
    vector<vector<int>> arr(n, vector<int>(n, 0));
    
    int d;
    if(horizontal)
        d = 1;
    else
        d = 0;

    int sec = -1;
    int cy = 0, cx = 0, dir = 0;;
    for(int i = 0; i < n; i++) {
        arr[cy][cx] = ++sec;
    
        for(int j = 0; j < i; j++) {
            cy += dy[dir];
            cx += dx[dir];
            sec += 2;
            arr[cy][cx] = sec;
        }
        
        if(i % 2 == d) {
            if(i == n - 1)
                cx++;
            else 
                cy++;
            dir = 0;
        } else {
            if(i == n - 1)
                cy++;
            else
                cx++;
            dir = 1;
        }
    }
    
    for(int i = n - 2; i >= 0; i--) {
        arr[cy][cx] = ++sec;
        
        for(int j = 0; j < i; j++) {
            cy += dy[dir];
            cx += dx[dir];
            sec += 2;
            arr[cy][cx] = sec;
        }
        
        if(i % 2 == d) {
            cx++;
            dir = 0;
        } else {
            cy++;
            dir = 1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            temp.push_back(arr[i][j]);
        }
        answer.push_back(temp);
    }

    return answer;
}