/*
    https://m.blog.naver.com/PostView.nhn?blogId=edenooo&logNo=222087623398&proxyReferer=https:%2F%2Fblog.naver.com%2Fedenooo%2F222087623398
*/
#include <string>
#include <algorithm>

#include <iostream>

using namespace std;

string solution(string new_id) {

    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    for(int i = 0; i < new_id.length(); i++) {
        if(!isalpha(new_id[i]) && !isdigit(new_id[i])) {
            if(new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') {
                new_id.erase(i, 1);
                i--;
            }    
        }
    }
    
    string temp = "";
    for(int i = 0; i < new_id.length(); i++) {
        if(new_id[i] == '.' && temp[temp.length()-1] == '.') continue;
        
        temp += new_id[i];
    }
    new_id = temp;

    // 4단계
    if(new_id[0] == '.') new_id = new_id.substr(1);
    if(new_id[new_id.length()-1] == '.') new_id = new_id.substr(0, new_id.length()-1);
    
    // 5단계
    if(new_id.empty()) new_id = "a";
    
    // 6단계
    if(new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
        
        if(new_id[new_id.length()-1] == '.') new_id = new_id.substr(0, new_id.length()-1);
    }
    
    // 7단계
    if(new_id.length() <= 2) {
        char last = new_id[new_id.length()-1];
        while(new_id.length() != 3) {
            new_id += last;
        }
    }
    
    return new_id;
}

int main(void) {

    string new_id = "abcdefghijklmn.p";
    cout << solution(new_id) << "\n";

    return 0;
}