#include<iostream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;

class Point {
public:
	double x, y;
	Point() {}
	Point(double x, double y) :x(x), y(y) {}
};

double destion2(const Point&p1, const Point&p2) {
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
class gameEvent {
public:
	void read() {
		double x, y;
		cin >> x >> y;
		enemy = Point(x, y);
		cin >> x >> y;
		hero = Point(x, y);
	}
	Point enemy, hero;
};

//int main() {
//	return 0;
//}