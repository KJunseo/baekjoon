#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int k, vector<int> score) {
    map<int, vector<int> > m;
    vector<bool> check(score.size() + 1, false);

    int current = score[0];
    for(int i = 1; i < score.size(); i++) {
        int idx = current - score[i];
        m[idx].push_back(i);
        m[idx].push_back(i+1);

        current = score[i];
    }

    map<int, vector<int> >::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        int size = it->second.size();
        if(size / 2 >= k) {
            for(int i = 0; i < size; i++) {
                if(check[it->second[i]]) continue;
                check[it->second[i]] = true;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i < check.size(); i++) {
        if(!check[i]) cnt++;
    }

    return cnt;
}