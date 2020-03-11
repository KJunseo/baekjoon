/*
    키 순서대로 정렬된 상태로 값을 받아오기 때문에, 
    본인의 값 만큼 본인의 왼편의 빈 자리를 카운트하여 
    그 자리부터 자리가 차 있는지 비어있는지를 검사하는 식으로 구현하려 하였으나 실패하였다.

    왼편에 본인보다 큰 사람의 수를 입력받고, 그 값을 하나씩 빼줄 때 마다, 
    자리를 한 칸씩 옮기면서 해당 자리가 비어있는지 체크하는 식으로 구현하였다.

    어찌저찌 알고리즘은 알아내더라도, 아직 그걸 구현하는 능력이 부족한 것 같다.
*/
#include <stdio.h>
#define MAX 11

int result[MAX];

int main(void) {
    int num;
    int left; // 현재 본인의 왼편에 본인보다 큰 사람의 수
    
    scanf("%d", &num);

    // i는 줄을 설 사람의 키 순위(1이 가장 작은 사람)
    for(int i=1;i<=num;i++) {
        scanf("%d", &left);

        // j는 빈 자리를 검사하는 용도(왼 편에 더 이상 큰 사람이 없더라도, 자리가 비어있지 않으면, 다음 자리로 가야하기 때문)
        for(int j=0;j<num;j++) {
            if(left==0 && result[j]==0) { // 왼 쪽에 더 이상 지나칠 큰 사람이 없고, 빈 자리인 경우
                result[j]=i;
                break;
            } else if(result[j]==0) { // 비어있기만 한 경우
                left--; // 큰 사람을 한 명 지나쳤으므로, 왼 편의 큰 사람 수를 하나 빼준다.
            }
        }
    }

    for(int i=0;i<num;i++) {
        printf("%d ", result[i]);
    }

    return 0;
}