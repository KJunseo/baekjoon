#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int left(int n) {
    int dir;
    if(n == 3) dir = 2;
    else if(n == 2) dir = 1;
    else if(n == 1) dir = 0;
    else dir = 3;
    
    return dir;
}

int back(int n) {
    int dir;
    if(n == 3) dir = 1;
    else if(n == 2) dir = 0;
    else if(n == 1) dir = 3;
    else dir = 2;
    
    return dir;
}

bool canLeft(vector<vector<int> >& maze, pair<int, int>& cur, int dir) {
    if(dir == 0) {
        if(maze[cur.first][cur.second-1] == 1 || cur.second-1 < 0) return false; 
    } else if(dir == 1) {
        if(maze[cur.first-1][cur.second] == 1 || cur.first-1 < 0) return false;
    } else if(dir == 2) {
        if(maze[cur.first][cur.second+1] == 1 || cur.second+1 >= maze.size()) return false;
    } else {
        if(maze[cur.first+1][cur.second] == 1 || cur.first+1 >= maze.size()) return false;
    }
        
    return true;
}

bool canStraight(vector<vector<int> >& maze, pair<int, int>& cur, int dir) {
    if(dir == 0) {
        if(maze[cur.first-1][cur.second] == 1 || cur.first-1 < 0) return false; 
    } else if(dir == 1) {
        if(maze[cur.first][cur.second+1] == 1 || cur.second+1 >= maze.size()) return false;
    } else if(dir == 2) {
        if(maze[cur.first+1][cur.second] == 1 || cur.first+1 >= maze.size()) return false;
    } else {
        if(maze[cur.first][cur.second-1] == 1 || cur.second-1 < 0) return false;
    }
        
    return true;
}

int solution(vector<vector<int> > maze) {
    int time = 1;
    int dir; // 0: 북, 1: 동, 2: 남, 3: 서
    queue<pair<int, int> > q;
    
    q.push(make_pair(0, 0));
    
    if(maze[0][1] == 1) {
        dir = 2;
    } else {
        dir = 1;
    }
    
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        cout << "y: " <<  cur.first << " | x: " << cur.second << " | dir: " << dir << "\n";

        if(canLeft(maze, cur, dir)) {
            dir = left(dir);
        
            if(!canStraight(maze, cur, dir)) {
                q.push(cur);
                continue;
            }
        } else {
            if(!canStraight(maze, cur, dir)) {
                dir = back(dir);
                q.push(cur);
                continue;
            }
        }
        
        int ny = cur.first + dy[dir];
        int nx = cur.second + dx[dir];
        
        if(ny < 0 || nx < 0 || ny >= maze.size() || nx >= maze.size()) continue;
        if(maze[ny][nx] == 1) continue;
        
        if(ny == maze.size()-1 && nx == maze.size()-1) {
            break;
        }
        
        time++;
        q.push(make_pair(ny, nx));
    }
    
    return time;
}