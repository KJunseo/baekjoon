// 정확성 100
// 효율성 0
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Person {
    string language, field, career, food;
    int coding;
};

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<Person> people;
    
    for(int i = 0; i < info.size(); i++) {
        stringstream ss(info[i]);
        string language, field, career, food;
        int coding;
        
        ss >> language >> field >> career >> food >> coding;
        
        Person person = {language, field, career, food, coding};
        people.push_back(person);   
    }
    
    for(int i = 0; i < query.size(); i++) {
        stringstream ss(query[i]);
        string language, field, career, food;
        string connect;
        int coding;
        
        ss >> language >> connect >> field >> connect >> career >> connect >> food >> coding;
    
        int ret = people.size();
        for(int j = 0; j < people.size(); j++) {
            if(language != "-") {
                if(people[j].language != language) {
                    ret--;
                    continue;
                }
            } 

            if(field != "-") {
                if(people[j].field != field) {
                    ret--;
                    continue;
                }
            }

            if(career != "-") {
                if(people[j].career != career) {
                    ret--;
                    continue;
                }
            }

            if(food != "-") {
                if(people[j].food != food) {
                    ret--;
                    continue;
                }
            }
            
            if(coding > people[j].coding) {
                ret--;
                continue;
            }
        }
        
        answer.push_back(ret);
    }
    
    return answer;
}