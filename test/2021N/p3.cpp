#include <string>
#include <string.h>

using namespace std;

int eachNum [] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long arr[51];
int zeroCnt = 0;

long long solve(int num) {

    long long& ret = arr[num];
    if(ret != 0) return ret;

    for(int i = 0; i < 10; i++) {
        if(num < eachNum[i]) continue;
        else if(num == eachNum[i]) ret++;
        else ret += solve(num - eachNum[i]);

        if(num - eachNum[i] == 6) zeroCnt++;
    }

    return ret;
}

long long solution(int k) {    
    memset(arr, 0, sizeof(arr));

    return solve(k) - zeroCnt;
}

int main(void) {

    int n;

    scanf("%d", &n);

    printf("%lld\n", solution(n));

    return 0;
}