#include <cmath>
#include <vector>

#include "Polygon.h" 
#include "Circle.h"
#include "Reuleaux.h"


Polygon::Polygon(std::vector<Point> vertices){
        vertices_ = std::vector<Point>(vertices);
}

std::vector<Point> Polygon::Vertices(){
        return vertices_;
}

static double distance(const Point &a, const Point &b){
       return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

//from previous
static bool point_in_pent(std::vector<Point> points, const Point &vertex){
        for(int i = 0, j = 4; i < 5; j=i++){
                if(((points[i].y > vertex.y) != (points[j].y > vertex.y)) && (vertex.x < (points[j].x - points[i].x) * (vertex.y - points[i].y) / (points[j].y - points[i].y) + points[i].x)){
                        return true;
                }
        }
        return false;
}

//Borrowed From Class

bool Polygon::ContainedBy(Circle &circle){
        for(unsigned short x = 0; x < Vertices().size(); x++){
                if(distance(Vertices()[x], circle.Center()) > circle.Radius()){
                        return false;
                }
        }
        return true;
}

//from previous
bool Polygon::ContainedBy(Polygon &polygon){
        for(unsigned short i = 0; i < Vertices().size(); i++){
                if(point_in_pent(polygon.Vertices(), Vertices()[i])){
                        return true;
                }
        }
        return false;
}

bool Polygon::ContainedBy(ReuleauxTriangle &rt){
	return true;
}
