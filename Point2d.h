
#ifndef POINT2D_H
#define POINT2D_H
using namespace std;

#include<string>


class Point2d {
public:
	Point2d();
	Point2d(const int x, const int y);
	Point2d(const Point2d& orig);
	Point2d* operator=(const Point2d& p);
	bool isEqual(const Point2d* p);
	int getX();
	int getY();
	void setX(const int x);
	void setY(const int y);
	string toString();

private:
	int _x, _y;

};

#endif /* POINT2D_H */

