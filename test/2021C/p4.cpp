#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > grid;
vector<bool> visit;
int pathCnt = 0;
void dfs(int from, int to) {

    if(from == to) {
        pathCnt++;
    } else {
        for(int i = 0; i < grid[from].size(); i++) {
            if(grid[from][i] == 1 && !visit[i]) {
                visit[i] = true;
                dfs(i, to);
                visit[i] = false;
            }
        }
    }
}

int solution(string depar, string hub, string dest, vector<vector<string>> roads) {
    map<string, int> m;

    int idx = 0;
    for(int i = 0; i < roads.size(); i++) {
        if(m.find(roads[i][0]) == m.end()) {
            m.insert(make_pair(roads[i][0], idx));
            idx++;
        }

        if(m.find(roads[i][1]) == m.end()) {
            m.insert(make_pair(roads[i][1], idx));
            idx++;
        }
    }

    grid.resize(m.size(), vector<int>(m.size(), 0));
    visit.resize(m.size(), false);
    for(int i = 0; i < roads.size(); i++) {
        int from = m[roads[i][0]];
        int to = m[roads[i][1]];

        grid[from][to] = 1;
    }

    int answer = 0;
    int start = m[depar];
    int end = m[hub];
    visit[start] = true;
    dfs(start, end);

    answer = pathCnt;

    pathCnt = 0;
    for(int i = 0; i < m.size(); i++) {
        visit[i] = false;
    }

    start = m[hub];
    end = m[dest];
    visit[start] = true;
    dfs(start, end);

    answer *= pathCnt;

    return answer;
}