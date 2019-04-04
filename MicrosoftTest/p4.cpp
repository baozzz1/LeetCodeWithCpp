#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<math.h>
using namespace std;
class Point {
public:
	int x, y;
	Point() {}
	Point(int x, int y) :x(x), y(y) {}
	bool operator<(const Point &p2)const {
		return x < p2.x;
	}
};

double distance(const Point &p1, const Point &p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
bool rua = true;
Point flower2honeycomb(const Point &start, const vector<Point> &honeycombs, double &lastTime, const Point &home) {
	if (lastTime < 0) {
		rua = false;
		return Point(0, 0);
	}
	int dis;
	double minDistance = 2147483647L;
	int minIndex = 0;
	for (int i = 0; i < honeycombs.size(); i++) {
		dis = distance(honeycombs[i], start);
		//distance2 =(honeycombs[i].x - start.x)*(honeycombs[i].x - start.x)+(honeycombs[i].y - start.y)*(honeycombs[i].y - start.y);
		if (dis < minDistance) {
			minDistance = dis;
			minIndex = i;
		}
	}
	lastTime -= minDistance;
	double distance2home = distance(honeycombs[minIndex], home);
	if (distance2home < lastTime) {
		rua = false;
	}
	return honeycombs[minIndex];
}
set<Point>::iterator honeycomb2flower(const Point &start, const set<Point> &flowers, double &lastTime, const Point &home) {
	if (lastTime < 0) {
		rua = false;
		return flowers.end();
	}
	int dis;
	double minDistance = 2147483647L;
	set<Point>::iterator minIter = flowers.begin();
	for (set<Point>::iterator iter = flowers.begin(); iter != flowers.end(); ++iter) {
		dis = distance(*iter, start);
		if (dis < minDistance) {
			minDistance = dis;
			minIter = iter;
		}
	}
	lastTime -= minDistance;
	return minIter;
}

// Read only region start

int honey(int input1, int input2, int **input3, int **input4, int input5[], int input6)
{
	// Read only region end
	// Write code and remove the below exception.
	set<Point> flowers;
	vector<Point> honeycombs;
	for (int i = 0; i < input1; i++) {
		flowers.insert(Point(input3[i][0], input3[i][0]));
	}
	for (int i = 0; i < input2; i++) {
		honeycombs.push_back(Point(input4[i][0], input4[i][0]));
	}
	Point start(input5[0], input5[1]);
	int res = 0;
	double lastTime = input6;
	int distance2;
	long minDistance2 = 2147483647L;
	set<Point>::iterator minIter = flowers.begin();
	for (set<Point>::iterator iter = flowers.begin(); iter != flowers.end(); ++iter) {
		distance2 = (start.x - iter->x)*(start.x - iter->x) + (start.y - iter->y)*(start.y - iter->y);
		if (distance2 < minDistance2) {
			minDistance2 = distance2;
			minIter = iter;
		}
	}
	double dis = sqrt(minDistance2);
	if (dis > input6)
		return res;
	lastTime = lastTime - dis;
	res++;
	int num;
	Point home = start;
	while (lastTime > 0) {
		start = flower2honeycomb(*minIter, honeycombs, lastTime, home);
		if (!rua) break;
		res++;
		flowers.erase(*minIter);
		minIter = honeycomb2flower(start, flowers, lastTime, home);
	}
	return res;
}
int main() {
	return 0;
}