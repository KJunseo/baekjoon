#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> partialSum(const vector<int>& v) {
    vector<int> ret(v.size());
    ret[0] = v[0];
    
    for(int i = 1; i < v.size(); i++) {
        ret[i] = ret[i-1] + v[i];
    }
    
    return ret;
}

int rangeSum(const vector<int>& psum, int a, int b) {
    if(a == 0) return psum[b];
    return psum[b] - psum[a-1];
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int ret = 0;
    
    vector<pair<int, int> > sec;
    vector<int> v(360000);
    
    if(play_time == adv_time) return "00:00:00";
        
    int adv_h = stod(adv_time.substr(0, 2)) * 3600;
    int adv_m = stod(adv_time.substr(3, 2)) * 60;
    int adv_s = stod(adv_time.substr(6, 2));
    
    int adv = adv_h + adv_m + adv_s;
    
    for(int i = 0; i < logs.size(); i++) {
        int sh = stod(logs[i].substr(0, 2)) * 3600;
        int sm = stod(logs[i].substr(3, 2)) * 60;
        int ss = stod(logs[i].substr(6, 2));
        int totalS = sh + sm + ss;
        
        int eh = stod(logs[i].substr(9, 2)) * 3600;
        int em = stod(logs[i].substr(12, 2)) * 60;
        int es = stod(logs[i].substr(15, 2));
        int totalE = eh + em + es;
        
        for(int j = totalS; j <= totalE; j++) v[j]++;
        
        sec.push_back(make_pair(sh+sm+ss, eh+em+es));
    }
    
    vector<int> psum = partialSum(v);
    
    int maxCnt = 0;
    for(int i = 0; i <= 359999; i++) {
        int start = i;
        int end = start + adv;
        if(end >= 360000) {
            end = 359999;
            start = end - adv;
        }
        
        int count = rangeSum(psum, start, end);
        if(maxCnt < count) {
            maxCnt = count;
            ret = start;
        }
    }

    int h, m, s;
    h = ret / 3600;
    ret = ret - (3600 * h);
    
    m = ret / 60;
    ret = ret - (60 * m);
    
    s = ret;
    
    string hour="", minute="", second="";
    if(h < 10) hour += "0";
    hour+=to_string(h);
    
    if(m < 10) minute += "0";
    minute+=to_string(m);
    
    if(s < 10) second += "0";
    second+=to_string(s);

    answer = hour + ':' + minute + ":" + second;
    
    return answer;
}