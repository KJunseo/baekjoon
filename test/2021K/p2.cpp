#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> combination(int n, int k) {
    vector<int> ret;
    
    for(int i = 0; i < n-k; i++) ret.push_back(0);
    for(int i = 0; i < k; i++) ret.push_back(1);
    
    return ret;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
        
    for(int i = 0; i < course.size(); i++) {
        map<string, int> m;
        
        for(int j = 0; j < orders.size(); j++) {
            vector<int> comb = combination(orders[j].length(), course[i]);
            
            do {
                string temp = "";
                for(int k = 0; k < comb.size(); k++) {
                    if(comb[k] == 1) {
                        temp += orders[j][k];
                    }
                }
                
                for(int k = 0; k < temp.length(); k++) {
                    if(!isalpha(temp[k])) {
                        temp = temp.substr(0, k-1);
                        break;
                    }
                }
            
                if(temp.length() == course[i]) {
                    sort(temp.begin(), temp.end());
                    m[temp]++;
                }
                
            } while(next_permutation(comb.begin(), comb.end()));
        }
        
        map<string, int>::iterator it;
        int maxCnt = 0;
        for(it = m.begin(); it != m.end(); it++) {
            if(maxCnt < it->second) maxCnt = it->second;
        }
        
        for(it = m.begin(); it != m.end(); it++) {
            if(it->second > 1 && it->second == maxCnt) {
                string temp = it->first;
                answer.push_back(temp);
            }
        }
        
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}