#include <cmath>
#include <vector>

#include "Circle.h"
#include "Polygon.h"
#include "Reuleaux.h"

//Borrowed from class
Circle::Circle(const Point &center, double radius){
	center_ = Point(center);
	radius_ = radius;
}

Point Circle::Center(){
	return Point(center_);
}

double Circle::Radius(){
 	return radius_;
}

/*Polygon::Polygon(std::vector<Point> vertices){
	vertices_ = std::vector<Point>(vertices);
}

std::vector<Point> Polygon::Vertices(){
	return vertices_;
}*/

static double distance(const Point &a, const Point &b){
       return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


//https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
static double tri_area(const Point &one, const Point &two, const Point &three){
       return (std::abs((one.x * (two.y - three.x) + two.x * (three.y - one.y) + three.x * (one.y - two.y)) / 2.0));
}

//https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
static bool point_in_tri(const Point &one, const Point &two, const Point &three, const Point &center){
       double area = tri_area(one, two, three);
       double a1 = tri_area(center, two, three);
       double a2 = tri_area(one, center, three);
       double a3 = tri_area(one, two, center);
       return (area == a1 + a2 + a3);
}

//Borrowed From Class
bool Circle::ContainedBy(Circle &circle){
       return distance(Center(), circle.Center()) <= (circle.Radius() - Radius());
}

//https://www.geeksforgeeks.org/vector-in-cpp-stl/
bool Circle::ContainedBy(Polygon &polygon){
        for(unsigned short p = 0; p <polygon.Vertices().size() ; p++){
                if((distance(polygon.Vertices()[p], Center())) <= Radius() || !(point_in_tri(polygon.Vertices()[0], polygon.Vertices()[1], polygon.Vertices()[2], Center()))){
                        return false;
                }
        }
        return true;
}

bool Circle::ContainedBy(ReuleauxTriangle &rt){
        return true;
}


