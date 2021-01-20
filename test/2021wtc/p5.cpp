#include <string>
#include <vector>

using namespace std;

string solution(string penter, string pexit, string pescape, string data) {
    string answer = "";
    int psize = penter.length();
    
    string data_str = "";
    for(int i = 0; i < data.length(); i += psize) {
        string sub_data = data.substr(i, psize);
        
        string temp = "";
        if(sub_data == penter || sub_data == pexit || sub_data == pescape) {
            temp += pescape;
        }
        
        temp += sub_data;
        
        data_str += temp;
    }
    
    answer += penter;
    answer += data_str;
    answer += pexit;
    
    return answer;
}