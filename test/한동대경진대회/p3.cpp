#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
};

struct Rect {
	int top, bottom, right, left;
	Rect() {}
	Rect(Point p1, Point p2) {
		top = max(p1.y, p2.y);
		bottom = min(p1.y, p2.y);
		right = max(p1.x, p2.x);
		left = min(p1.x, p2.x);
	}
};

int get_width(Rect &r1, Rect &r2) {
	int top = min(r1.top, r2.top);
	int bottom = max(r1.bottom, r2.bottom);
	int right = min(r1.right, r2.right);
	int left = max(r1.left, r2.left);
	
	int w = right - left;
	int h = top - bottom;

	if(w >= 0 && h >= 0)
		return w * h;

	return 0;
}

int main() {
	Rect r[2];
	for(int i = 0; i < 2; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d", &x1, &y1);
		scanf("%d %d", &x2, &y2);
		r[i] = Rect(Point(x1, y1), Point(x2, y2));
	}
	
	int answer = get_width(r[0], r[1]);
	printf("%d\n", answer);
	
	return 0;
}
