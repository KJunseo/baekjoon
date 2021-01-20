#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<pair<int, int> > > adj(n+1, vector<pair<int, int> >());
    
    for(int i = 0; i < fares.size(); i++) {
        adj[fares[i][0]].push_back(make_pair(fares[i][1], fares[i][2]));
        adj[fares[i][1]].push_back(make_pair(fares[i][0], fares[i][2]));
    }
    
    
    return answer;
}