#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<math.h>

using namespace std;

class Point {
public:
	double x, y;
	Point() {}
	Point(double x, double y) :x(x), y(y) {}
	Point(int x, int y) :x(double(x)), y(double(y)) {}
};
class gameEvent {
public:
	gameEvent(int ex,int ey,int hx,int hy) {
		Point enemy(ex, ey);
		Point hero(hx, hy);
	}
	double f(const Point &p) {
		double res = 0;
		res = exp(getN(enemy, p)) + exp(getN(obst1, p)) + exp(getN(obst2, p)) + exp(getN_bound(p));
	}



private:
	double getN(const Point &p1, const Point &p2) {
		return -((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)) / 10000;
	}
	double getN_bound(const Point &p) {
		double x2y2 = p.x*p.x + p.y*p.y;
		return -(10000 + x2y2 - 200 * pow(x2y2, 0.5)) / 10000;
	}

	double getDeltaN(const Point &p1, const Point &p2) {
		//TO BE CONTINUED
		return 0.0;
	}
	Point enemy;
	Point hero;
	static Point obst1, obst2;
	Point center;
};

Point gameEvent::obst1(-50, 0);
Point gameEvent::obst2(50, 0);

int main() {

	return 0;
}