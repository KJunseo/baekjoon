/*
    dp문제를 처음 풀어봤는데, 너무 어려웠다.

    주어진 수를 통해 만들 수 있는 경우의 수는 크게 보면 2가지가 있다.
    1. 이어서 표현하는 방식 -> ex. 5가 주어진 수라면, 55, 555, 5555 이런식으로 표현하는 방법
    2. 사칙연산을 통해 표현하는 방식 -> ex. 5가 주어진 수라면, 5+5, 5-5, 5*5, 5/5 이런식으로 표현하는 방법

    계속해서 5를 통해 설명해보겠다.
    제일 처음은 5밖에 가능하지 않다.
    두 번째 부터, 55와 5+5, 5-5, 5*5, 5/5 로 경우가 생긴다. (5를 두 번 사용한 경우)
    세 번째를 보면, 555 / 두 번째에서 만든 결과들(55, 10, 0, 25, 1)을 5와 사칙연산한 값 / 5와 두 번째에서 만든 결과들(55, 10, 0, 25, 1)을 사칙연산 한 값 (순서를 바꿔주는 이유는, 순서가 달라지면 값이 변할 수 있기 때문)(5를 세 번 사용한 경우)
    네 번째는, 5555 / 세 번째에서 만든 결과들과 5를 사칙연산 한 값 / 두 번째에서 만든 결과들과 두 번째에서 만든 결과들의 사칙연산 한 값 / 5와 세 번째에서 만든 결과들을 사칙연산 한 값(5를 네 번 사용한 경우)
    ...

    이런식으로 8까지 진행 후, number을 찾지 못하면 -1을 출력해주고, 아니면 찾은 번째를 return 해준다.

    위의 설명을 N으로 표시하면 아래와 같다.
    <N을 n번 사용해서 만들 수 있는 수의 집합>
    N을 n번 이어붙인 수 &&
    N을 1번 사용한 수와 N을 n-1번 사용한 수들의 사칙연산 한 값들의 집합 &&
    N을 2번 사용한 수와 N을 n-2번 사용한 수들의 사칙연산 한 값들의 집합 &&
    N을 3번 사용한 수와 N을 n-3번 사용한 수들의 사칙연산 한 값들의 집합 &&
    ...
    N을 n-1번 사용한 수와 N을 1번 사용한 수들의 사칙연산 한 값들의 집합


    8사이즈의 벡터를 선언하여, 각각 벡터에 가능한 수들의 집합을 담아준다.
    각 벡터마다, N을 이어붙인 수를 초기화해준다. ex. s[0] = {N} / s[1] = {NN} / s[2] = {NNN} ...

    그 후, 8번까지 돌면서, 각각 집합에 가능한 경우들을 추가해주면서 number를 발견하면 index+1을 리턴해주면 된다.
*/
#include <string>
#include <vector>
#include <set>
#include <iostream>
#define MIN 8

using namespace std;

int solution(int N, int number) {
    int answer = -1; 
    vector<set<int> > s(MIN); // N을 1번~8번 사용하는 경우를 담는 벡터
    string temp;

    // 연산없이 이어붙이는 경우 추가
    for(int i=0;i<s.size();i++) {
        temp="";
        for(int j=0;j<i+1;j++) {
            temp+=to_string(N);
        }
        s[i].insert(stoi(temp));
    }

    /*
        <N을 n번 사용해서 만들 수 있는 수의 집합>
        N을 n번 이어붙인 수 &&
        N을 1번 사용한 수와 N을 n-1번 사용한 수들의 사칙연산 한 값들의 집합 &&
        N을 2번 사용한 수와 N을 n-2번 사용한 수들의 사칙연산 한 값들의 집합 &&
        N을 3번 사용한 수와 N을 n-3번 사용한 수들의 사칙연산 한 값들의 집합 &&
        ...
        N을 n-1번 사용한 수와 N을 1번 사용한 수들의 사칙연산 한 값들의 집합
    */
    for(int i=1;i<MIN;i++) {
        for(int j=0;j<i;j++) {
            for(auto op1 : s[j]) {
                for(auto op2 : s[i-j-1]) {
                    s[i].insert(op1+op2);
                    s[i].insert(op1-op2);
                    s[i].insert(op1*op2);
                    if(op2!=0) s[i].insert(op1/op2);
                }
            }
        }

        // number를 발견하면 종료
        if(s[i].find(number)!=s[i].end()) {
            answer=i+1;
            break;
        }
    }

    return answer;
}