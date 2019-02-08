// baekjoon 10255 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

#define DEBUG_MODE
// const int answer[16] = {0,1,0,2,0,0,1,4,1,1,1,2,2,2,4,4};

struct Pos{
	int x;
	int y;
	Pos():x(0),y(0) {}
	Pos(int x_in, int y_in) { x=x_in; y=y_in; }
	void Print() { printf("(%d, %d)\n", x, y); }
};

struct Line{
	Pos a;
	Pos b;
	Line(){}
	Line(Pos a_in, Pos b_in):a(a_in), b(b_in){}
	void Print() {
		printf("Print Line Pos\n");
		a.Print(); b.Print();
		puts("");
	}
};

struct Rect{
	Pos pos[4];
	Rect(){}
	Rect(Pos a, Pos b) {
		pos[0].x = pos[3].x = a.x;
		pos[0].y = pos[1].y = a.y;
		pos[1].x = pos[2].x = b.x;
		pos[2].y = pos[3].y = b.y;
	}
	void Print() {
		printf("Print RECT POS\n");
		pos[0].Print(); pos[1].Print(); pos[2].Print(), pos[3].Print();
		puts("");
	}
};

bool isPosgreater(Pos a, Line line) {
	return (a.x > line.a.x && a.x > line.b.x) || \
			(a.y > line.a.y && a.y > line.b.y);
}

bool isPosless(Pos a, Line line) {
	return (a.x < line.a.x && a.x < line.b.x) || \
			(a.y < line.a.y && a.y < line.b.y);
}

bool isRectOut(Rect rect, Line line) {
	return (isPosgreater(rect.pos[0], line) || isPosless(rect.pos[2], line));
}

bool isRectPos(Rect rect, Pos pos) {
	return (rect.pos[0].x < pos.x && rect.pos[0].y < pos.y) && \
			(rect.pos[2].x > pos.x && rect.pos[2].y > pos.y);
}

bool isRectIn(Rect rect, Line line) {
	return isRectPos(rect, line.a) && isRectPos(rect, line.b);
}

bool isISTPoint(Rect rect, Line line) {
	if (isRectOut(rect, line)) return false;
	if (isRectIn(rect, line)) return false;
	return true;
}

int CheckCW(Pos a, Pos b, Pos c) {
	int res = (a.x*b.y + b.x*c.y + c.x*a.y);
	res -= (a.x*c.y + b.x*a.y + c.x*b.y);
	return (res) ? ((res < 0) ? -1 : 1) : 0;
}

int CountISTPoint(Rect rect, Line line) {
	int cw[4];
	for (int i=0; i<4; i++)
		cw[i] = CheckCW(rect.pos[i], line.a, line.b);

#ifdef DEBUG_MODE
	printf("CW: ");
	for (int i=0; i<4; i++)
		printf("%d ", cw[i]);
	puts("");
#endif
	
	int count = 0;
	int zeronum = 0;
	for (int i=0; i<4; i++) {
		if (cw[i] == 0) zeronum++;
		if (cw[i] != cw[(i+1)%4]) count++;
		if (cw[i] == 0 && cw[i] == cw[(i+1)%4]) {
			if (i%2) { // y
				int ymin = min(rect.pos[i].y, rect.pos[(i+1)%4].y);
				int ymax = max(rect.pos[i].y, rect.pos[(i+1)%4].y);
				if (ymin == max(line.a.y, line.b.y) || \
					ymax == min(line.a.y, line.b.y) ) return 1;
			} else { // x
				int xmin = min(rect.pos[i].x, rect.pos[(i+1)%4].x);
				int xmax = max(rect.pos[i].x, rect.pos[(i+1)%4].x);
				if (xmin == max(line.a.x, line.b.x) || \
					xmax == min(line.a.x, line.b.x) ) return 1;
			}
			return 4;
		}
	}
	if (count == 4) count = 2;
	if (count > 1) {
		if (zeronum == 1) count -= 1;
		if (isRectPos(rect, line.a) || isRectPos(rect, line.b)) count = 1;
	}
	return count;
}

int Solve(Rect rect, Line line) {
	if (!isISTPoint(rect, line)) return 0;
	// return 1;
	return CountISTPoint(rect, line);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i=0; i<T; i++){
	// while (T--) {
		int xmin, ymin, xmax, ymax;
		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
#ifdef DEBUG_MODE
		printf("Rect: %d %d %d %d\n", xmin, ymin, xmax, ymax);
#endif
		Rect rect(Pos(xmin, ymin), Pos(xmax, ymax));
		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
#ifdef DEBUG_MODE
		printf("Line: %d %d %d %d\n", xmin, ymin, xmax, ymax);
#endif
		Line line(Pos(xmin, ymin), Pos(xmax, ymax));
		printf("%d\n", Solve(rect, line));
		// puts("");
	}
	return 0;
}