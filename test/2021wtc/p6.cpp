#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

map<string, map<int, int> > m;

bool sameQ(map<int, int> m1, map<int, int> m2) {
    for(auto i = m1.begin(); i != m1.end(); i++) {
        if(m1[i->first] != m2[i->first])
            return false;
    }
    return true;
}

vector<string> solution(vector<string> logs) {
    vector<string> answer;
    
    for(int i = 0; i < logs.size(); i++) {
        stringstream ss(logs[i]);
        
        string id; 
        int num, score;
        ss >> id >> num >> score;
        
        map<int, int> temp_m = m[id]; 
        temp_m[num] = score;
        m[id] = temp_m;
    }
    
    for(auto i = m.begin(); i != m.end(); i++) {
        for(auto j = i; j != m.end(); j++) {
            if(i == j)
                continue;
            
            map<int, int> m1 = i->second;
            map<int, int> m2 = j->second;
            
            if(m1.size() >= 5 && (m1.size() == m2.size())) {
                if(sameQ(m1, m2)) {
                    answer.push_back(i->first);
                    answer.push_back(j->first);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    if(answer.size() == 0)
        answer.push_back("None");
    
    return answer;
}