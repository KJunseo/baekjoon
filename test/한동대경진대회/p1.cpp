#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y, p;
	scanf("%d %d %d", &x, &y, &p);
	
	int bigger = max(x, y);
	int smaller = min(x, y);
	
	while(smaller < bigger) {
		if(p == 0)
			break;
		smaller++;
		p--;
	}
	
	int answer = smaller;
	answer += (p / 2);
	
	printf("%d\n", answer * 2);
	
	return 0;
}
